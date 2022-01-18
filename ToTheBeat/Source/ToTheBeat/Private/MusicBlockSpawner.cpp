// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockSpawner.h"
#include "ToTheBeatGameInstance.h"
#include "MusicBlockManager.h"
#include "UMaterialManager.h"
#include "ModelManager.h"
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

	for (int32 i{}; i < fileContent.Len();)
	{
		const int32 newLineLocation{ fileContent.Find(TEXT("\n"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, i) };

		/* Check if we're not at the end of the file */
		if (newLineLocation != INDEX_NONE)
		{
			/* Get the current line */
			const FString line{ fileContent.Mid(i, newLineLocation - i) };

			/* Line looks this: */
			/* 0.3 Chord */
			/* or like this: */
			/* 6.000000000000001 Rest */

			const int32 spaceLocation{ line.Find(FString{ TEXT(" ") }) };
			if (line.Mid(spaceLocation + 1, line.Len() - spaceLocation - 1) != TEXT("Rest"))
				m_Times.Add(FCString::Atof(*line.Mid(0, spaceLocation)));
				
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

	if (m_Times.Num() <= 0 || m_Letters.Num() <= 0)
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

void AMusicBlockSpawner::SetDirection(const FVector& direction) noexcept
{
	m_Direction = direction;
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
	const FTransform* pFinalDestination{};
	FString text{};

	UToTheBeatGameInstance* const pGameInstance{ static_cast<UToTheBeatGameInstance*>(UGameplayStatics::GetGameInstance(GetWorld())) };
	const UMaterialManager* const pMaterialManager{ pGameInstance->GetMaterialManagerInstance() };
	AMusicBlockManager* const pMusicBlockManager{ pGameInstance->GetMusicBlockManagerInstance() };
	const UModelManager* const pModelManager{ pGameInstance->GetModelManagerInstance() };

	int32 materialIndex{};
	switch (c)
	{
	case 'W':
		pTransform = &m_pTransforms[0];
		text = TEXT("W");
		break;
	case 'A':
		pTransform = &m_pTransforms[1];
		materialIndex = 1;
		text = TEXT("A");
		break;
	case 'S':
		pTransform = &m_pTransforms[2];
		materialIndex = 2;
		text = TEXT("S");
		break;
	case 'D':
		pTransform = &m_pTransforms[3];
		materialIndex = 3;
		text = TEXT("D");
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("AAAAAAAAH"));
	}

	AActor* pActor{ GetWorld()->SpawnActor(m_BPMusicBlock, pTransform, FActorSpawnParameters{}) };
	AMusicBlock* pMusicBlock{ Cast<AMusicBlock>(pActor) };
	UStaticMeshComponent* const pStaticMeshComponent{ pMusicBlock->GetStaticMeshComponent() };

	pMusicBlock->SetDirection(m_Direction);
	pMusicBlock->SetText(FText::FromString(text));
	pMusicBlock->SetMusicBlockType(type);

	switch (type)
	{
	case MusicBlockType::Normal:
		pStaticMeshComponent->SetStaticMesh(pModelManager->GetMesh(FString{ TEXT("Cube") }));
		break;
	case MusicBlockType::Slowdown:
		pStaticMeshComponent->SetStaticMesh(pModelManager->GetMesh(FString{ TEXT("Timeturner") }));
		//materialIndex += 8;
		break;
	case MusicBlockType::Bomb:
		pStaticMeshComponent->SetStaticMesh(pModelManager->GetMesh(FString{ TEXT("Bomb") }));
		//materialIndex += 8;
		break;
	}

	pStaticMeshComponent->SetMaterial(0, pMaterialManager->GetMaterial(materialIndex));

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