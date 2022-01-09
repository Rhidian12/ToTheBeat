// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockSpawner.h"
#include "ToTheBeatGameInstance.h"
#include "MusicBlockManager.h"
#include "UMaterialManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AMusicBlockSpawner::AMusicBlockSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_TotalElapsedTime = 0.f;

	m_IsDelaySet = false;
	m_Delay = 0.f;
	m_DelayTimer = 0.f;

	m_SlowdownCounter = 0;
	m_BombCounter = 0;
}

// Called when the game starts or when spawned
void AMusicBlockSpawner::BeginPlay()
{
	Super::BeginPlay();

	ReadFile();

	m_InversePlayerForward = -GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector();
}

void AMusicBlockSpawner::ReadFile() noexcept
{
	/* whoever reads this, just, don't bring it up */
	/* you don't know how much of my mental sanity has disappeared */

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	FString path{ FPaths::ProjectContentDir() };
	path.Append(m_FileBeats);

	FString fileContent;
	if (FileManager.FileExists(*path))
	{
		if (FFileHelper::LoadFileToString(fileContent, *path, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("Successfully loaded file"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
		}
	}

	const float crotchetTime{ 60.f / m_BPM }; /* 1 minute divided by BPM */
	float previousCrotchet{ -1.f };
	bool trackFound{};
	for (int32 i{}; i < fileContent.Len();)
	{
		const int32 newLineLocation{ fileContent.Find(TEXT("\n"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, i) };

		/* Check if we're not at the end of the file */
		if (newLineLocation != INDEX_NONE)
		{
			/* Get the current line */
			const FString line{ fileContent.Mid(i, newLineLocation - i) };

			/* Check if we've found the track we want to get the notes out of */
			if (trackFound)
			{
				/* Check if we've reached the end of the track */
				if (line.Find(FString{ TEXT("End of track") }, ESearchCase::Type::CaseSensitive, ESearchDir::Type::FromStart) != INDEX_NONE)
				{
					trackFound = false;
					i = newLineLocation + 1;
					continue;
				}

				/* Check if the line contains a note instruction */
				const int32 noteInstruction{ line.Find(FString{ TEXT("NT") }, ESearchCase::Type::CaseSensitive, ESearchDir::Type::FromStart) };
				if (noteInstruction != INDEX_NONE)
				{
					/* A line with a note instruction looks like this: */
					/*BA    1   CR         0   TR  1   CH  1   NT  D             5/6   von=110 */
					/* von and voff are optional */
					/* But all we care about is NT and the first number after it */

					/* Get the number of the crotchet */
					const int32 crPos{ line.Find(TEXT("CR"), ESearchCase::Type::CaseSensitive) };
					const FString crotchetLine{ line.Mid(crPos, line.Find(TEXT("TR"), ESearchCase::Type::CaseSensitive) - crPos) };
					const float currentCrotchet{ GetCrotchet(crotchetLine) };

					if (AreEqual(previousCrotchet, currentCrotchet))
					{
						i = newLineLocation + 1;
						continue;
					}
					
					previousCrotchet = currentCrotchet;

					/* This should be: NT [NOTE] [LENGTH] <optional> [von] [voff] */
					const FString noteInstructionLine{ line.Mid(noteInstruction, line.Len() - noteInstruction) };

					const int32 digitLocation{ FindByPredicate(noteInstructionLine, [](const TCHAR c)->bool
							{
							/* check if the character is a digit */
							return static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57;
						}) };

					/* This should be: [LENGTH] <optional> [von] [voff] */
					FString numberString{ noteInstructionLine.Mid(digitLocation, noteInstructionLine.Len() - digitLocation) };

					int32 spacePos{};

					if (numberString.FindChar(' ', spacePos))
						numberString = numberString.Mid(0, spacePos);
					else
						spacePos = numberString.Len() - 1; /* final index is \n or \r */

					/* check if the number is an addition */
					int32 additionPos{};
					if (numberString.FindChar('+', additionPos))
					{
						TArray<float> numbers{};

						/* add the left sign of the addition */
						numbers.Add(FCString::Atof(*numberString.Mid(0, additionPos)));

						/* check if the addition contains a fraction, because life has to be hard */
						int32 fractionPos{};
						if (numberString.FindChar('/', fractionPos))
						{
							const float leftSide{ FCString::Atof(*numberString.Mid(additionPos + 1, numberString.Len() - fractionPos - additionPos)) };
							const float rightSide{ FCString::Atof(*numberString.Mid(fractionPos + 1, numberString.Len() - fractionPos)) };
							numbers.Add(leftSide / rightSide);
						}
						else /* no fraction */
						{
							/* add the right side of the addition */
							numbers.Add(FCString::Atof(*numberString.Mid(additionPos, numberString.Len() - additionPos)));
						}

						float result{};
						for (const float number : numbers)
							result += number;

						result *= crotchetTime;

						if (m_Times.Num() != 0)
							m_Times.Add(m_Times.Last() + result);
						else
							m_Times.Add(result);

						i = newLineLocation + 1;
						continue;
					}

					/* check if the number is a fraction */
					int32 fractionPos{};
					if (numberString.FindChar('/', fractionPos))
					{
						const float leftSide{ FCString::Atof(*numberString.Mid(0, fractionPos)) };
						const float rightSide{ FCString::Atof(*numberString.Mid(fractionPos + 1, numberString.Len() - fractionPos)) };

						const float result{ (leftSide / rightSide) * crotchetTime };

						if (m_Times.Num() != 0)
							m_Times.Add(m_Times.Last() + result);
						else
							m_Times.Add(result);

						i = newLineLocation + 1;
						continue;
					}

					/* if we get here, the number is neither a fraction or an addition */
					if (m_Times.Num() != 0)
						m_Times.Add(m_Times.Last() + (FCString::Atof(*numberString) * crotchetTime));
					else
						m_Times.Add(FCString::Atof(*numberString) * crotchetTime);
				}
			}
			else /* Search for the track */
			{
				/* Is this a comment? */
				if (line.Find(TEXT("#"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, -1) != INDEX_NONE)
				{
					/* Track comment should look like: # TRACK [number] */

					int32 spacePosition{};
					if (line.FindLastChar(' ', spacePosition))
						if (line.Mid(0, spacePosition) == FString{ TEXT("# TRACK") }) /* Is this comment a Track comment? */
							for (const int32 trackNumber : m_Tracks)
								if (FString::FromInt(trackNumber) == line.Mid(spacePosition + 1, 1))
									trackFound = true;
				}
			}

			i = newLineLocation + 1;
		}
		else
			++i;
	}

	path = FPaths::ProjectContentDir();
	path.Append(m_FileLetters);

	fileContent = TEXT("");
	if (FileManager.FileExists(*path))
	{
		if (FFileHelper::LoadFileToString(fileContent, *path, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("Successfully loaded file"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
		}
	}

	for (int32 i{}; i < fileContent.Len();)
	{
		const int32 newLineLocation{ fileContent.Find(TEXT("\n"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, i) };

		/* Check if we're not at the end of the file */
		if (newLineLocation != INDEX_NONE)
		{
			const FString line{ fileContent.Mid(i, newLineLocation - i) };

			m_Letters.Add(line[0]);

			i = newLineLocation + 1;
		}
		else
			++i;
	}

	while (m_Letters.Num() > m_Times.Num())
		m_Letters.Pop();

	if (m_Times.Num() != m_Letters.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("Array sizes don't match!\nTimes size: %i\nLetters size: %i"), m_Times.Num(), m_Letters.Num());
	}


	UE_LOG(LogTemp, Warning, TEXT("Final time: %f"), m_Times.Last());
}

// Called every frame
void AMusicBlockSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_IsDelaySet)
		return;
	else
	{
		if (m_DelayTimer < m_Delay)
		{
			m_DelayTimer += DeltaTime;
			return;
		}
	}

	m_TotalElapsedTime += DeltaTime;

	if (m_Times.Num() <= 0)
		return;

	if (m_TotalElapsedTime >= m_Times[0])
	{
		++m_SlowdownCounter;
		++m_BombCounter;

		if (m_SlowdownCounter % 20 == 0)
			SpawnBlock(m_Letters[0], MusicBlockType::Slowdown);
		else if (m_BombCounter % 33 == 0)
			SpawnBlock(m_Letters[0], MusicBlockType::Bomb);
		else
			SpawnBlock(m_Letters[0], MusicBlockType::Normal);

		m_Times.RemoveAt(0);
		m_Letters.RemoveAt(0);
	}
}

void AMusicBlockSpawner::AddTransform(const FTransform& transform) noexcept
{
	m_pTransforms.Add(transform);
}

void AMusicBlockSpawner::SetDelay(const float delay) noexcept
{
	m_Delay = delay;

	m_IsDelaySet = true;
}

bool AMusicBlockSpawner::AreNotesDone() const noexcept
{
	return m_Times.Num() <= 0;
}

void AMusicBlockSpawner::SpawnBlock(const char c, const MusicBlockType type) const noexcept
{
	if (!m_BPMusicBlock)
	{
		UE_LOG(LogTemp, Warning, TEXT("Music Block BP not set!"));
		return;
	}

	const FTransform* pTransform{};
	UMaterialInterface* pMaterial{};
	FString text{};

	UToTheBeatGameInstance* const pGameInstance{ static_cast<UToTheBeatGameInstance*>(UGameplayStatics::GetGameInstance(GetWorld())) };
	const UMaterialManager* const pMaterialManager{ pGameInstance->GetMaterialManagerInstance() };
	AMusicBlockManager* const pMusicBlockManager{ pGameInstance->GetMusicBlockManagerInstance() };

	switch (c)
	{
	case 'W':
		pTransform = &m_pTransforms[0];
		pMaterial = pMaterialManager->GetMaterial(0);
		text = TEXT("W");
		break;
	case 'A':
		pTransform = &m_pTransforms[1];
		pMaterial = pMaterialManager->GetMaterial(1);
		text = TEXT("A");
		break;
	case 'S':
		pTransform = &m_pTransforms[2];
		pMaterial = pMaterialManager->GetMaterial(2);
		text = TEXT("S");
		break;
	case 'D':
		pTransform = &m_pTransforms[3];
		pMaterial = pMaterialManager->GetMaterial(3);
		text = TEXT("D");
		break;
	}

	AActor* pActor{ GetWorld()->SpawnActor(m_BPMusicBlock, pTransform, FActorSpawnParameters{}) };
	AMusicBlock* pMusicBlock{ Cast<AMusicBlock>(pActor) };
	UStaticMeshComponent* const pStaticMeshComponent{ pMusicBlock->GetStaticMeshComponent() };

	pMusicBlock->SetDirection(m_InversePlayerForward);
	pMusicBlock->SetText(FText::FromString(text));
	pMusicBlock->SetMusicBlockType(type);

	switch (type)
	{
	case MusicBlockType::Normal:
		// pStaticMeshComponent->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object);
		break;
	case MusicBlockType::Slowdown:
		// pStaticMeshComponent->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'")).Object);
		break;
	}

	pStaticMeshComponent->SetMaterial(0, pMaterial);

	pMusicBlockManager->AddMusicBlock(pMusicBlock);
}

float AMusicBlockSpawner::GetCrotchet(FString line) const noexcept
{
	/* line will look like this: */
	/* CR		[NUMBER]	*/

	/* get rid of all information except the number */
	const int32 numberPos{ FindByPredicate(line, [](const TCHAR c)->bool
		{
			/* check if the character is a digit */
			return static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57;
		}) };
	line = line.Mid(numberPos, line.Len() - numberPos);

	/* check if the number is an addition */
	int32 additionPos{};
	if (line.FindChar('+', additionPos))
	{
		TArray<float> numbers{};

		/* add the left sign of the addition */
		const int32 digitPos{ FindByPredicate(line, [](const TCHAR c)->bool
		{
				/* check if the character is a digit */
				return static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57;
			}) };
		numbers.Add(FCString::Atof(*line.Mid(digitPos, additionPos - digitPos)));

		/* check if the addition contains a fraction, because life has to be hard */
		int32 fractionPos{};
		if (line.FindChar('/', fractionPos))
		{
			const float leftSide{ FCString::Atof(*line.Mid(additionPos + 1, line.Len() - fractionPos - additionPos)) };
			const float rightSide{ FCString::Atof(*line.Mid(fractionPos + 1, line.Len() - fractionPos)) };
			numbers.Add(leftSide / rightSide);
		}
		else /* no fraction */
		{
			/* add the right side of the addition */
			numbers.Add(FCString::Atof(*line.Mid(additionPos, line.Len() - additionPos)));
		}

		float result{};
		for (const float number : numbers)
			result += number;

		return result;
	}

	/* check if the number is a fraction */
	int32 fractionPos{};
	if (line.FindChar('/', fractionPos))
	{
		const float leftSide{ FCString::Atof(*line.Mid(0, fractionPos)) };
		const float rightSide{ FCString::Atof(*line.Mid(fractionPos + 1, line.Len() - fractionPos)) };

		return leftSide / rightSide;
	}

	const int32 startDigitLocation{ FindByPredicate(line, [](const TCHAR c)->bool
		{
			/* check if the character is a digit */
			return static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57;
		}) };

	int32 endDigitLocation{ startDigitLocation + 1 };

	while (true)
	{
		const int32 temp{ FindByPredicate(line, [](const TCHAR c)->bool
			{
				/* check if the character is a digit */
				return static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57;
			}, endDigitLocation + 1) };

		if (temp == INDEX_NONE)
			break;
		else
			endDigitLocation = temp;
	}

	return FCString::Atof(*line.Mid(startDigitLocation, endDigitLocation - startDigitLocation));
}

int32 AMusicBlockSpawner::FindByPredicate(const FString& fstring, bool (*predicate)(const TCHAR), const int32 startPos) const noexcept
{
	for (int32 i{ startPos }; i < fstring.Len(); ++i)
		if (predicate(fstring[i]))
			return i;

	return INDEX_NONE;
}

bool AMusicBlockSpawner::AreEqual(const float a, const float b) const noexcept
{
	const float epsilon{ FLT_MIN };

	return (fabs(a - b) <= epsilon);
}