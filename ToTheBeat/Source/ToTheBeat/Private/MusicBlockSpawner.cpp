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

	//FString path{ FPaths::ProjectContentDir() };
	//path.Append("SongBeats/Undertale - Megalovania.txt");

	//IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	//FString fileContent;
	//if (FileManager.FileExists(*path))
	//{
	//	if (FFileHelper::LoadFileToString(fileContent, *path, FFileHelper::EHashOptions::None))
	//	{
	//		//UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *fileContent);
	//		UE_LOG(LogTemp, Warning, TEXT("Successfully loaded file"));
	//	}
	//	else
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
	//	}
	//}

	//for (int32 i{}; i < fileContent.Len();)
	//{
	//	const int32 newLineLocation{ fileContent.Find(TEXT("\n"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, i) };

	//	if (newLineLocation != INDEX_NONE)
	//	{
	//		FString line{ fileContent.Mid(i, newLineLocation - i) };

	//		// UE_LOG(LogTemp, Warning, TEXT("Line %i :, %s"), i, *line);

	//		if (line.Find(TEXT("#"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, -1) == INDEX_NONE)
	//		{
	//			const int32 spacePos{ line.Find(TEXT(" "), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, -1) };

	//			if (spacePos != INDEX_NONE)
	//			{
	//				const FString time{ line.Mid(0, spacePos) };
	//				const FString letter{ line.Mid(spacePos + 1, 1) };

	//				m_Letters.Add(letter[0]);
	//				m_Times.Add(FCString::Atof(*time));
	//			}
	//		}

	//		i = newLineLocation + 1;
	//	}
	//	else
	//		++i;
	//}

	ReadFile();

	m_InversePlayerForward = -GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector();
}

void AMusicBlockSpawner::ReadFile() noexcept
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	FString path{ FPaths::ProjectContentDir() };
	path.Append(m_FileToRead);

	FString fileContent;
	if (FileManager.FileExists(*m_FileToRead))
	{
		if (FFileHelper::LoadFileToString(fileContent, *m_FileToRead, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("Successfully loaded file"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
		}
	}

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
					++i;
					continue;
				}

				/* Check if the line contains a note instruction */
				const int32 noteInstruction{ line.Find(FString{ TEXT("NT") }, ESearchCase::Type::CaseSensitive, ESearchDir::Type::FromStart) };
				if (noteInstruction != INDEX_NONE)
				{
					/* A line with a note instruction looks like this: */
					/* CR             0   (BA    1   CR         0)   TR  3   CH  1   NT  D             1/2   von=81   voff=0 */
					/* von and voff are optional */

					/* Get the length of the crotchet */

				}
			}
			else /* Search for the track */
			{

			}

			/* Is this a comment? */
			if (line.Find(TEXT("#"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, -1) != INDEX_NONE)
			{
				/* Track comment should look like: # TRACK [number] */

				int32 spacePosition{};
				if (line.FindLastChar(' ', spacePosition))
				{
					/* Is this comment a Track comment? */
					if (line.Mid(0, spacePosition) == FString{ TEXT("# TRACK") })
					{
						for (const int32 trackNumber : m_Tracks)
						{
							if (FString::FromInt(trackNumber) == line.Mid(spacePosition, 1))
								trackFound = true;

							++i; /* continue the loop */
						}
					}
				}
			}
		}
	}
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

	for (int32 i{}; i < m_Times.Num(); ++i)
	{
		if (m_TotalElapsedTime >= m_Times[i])
		{
			++m_SlowdownCounter;
			++m_BombCounter;

			if (m_SlowdownCounter % 20 == 0)
				SpawnBlock(m_Letters[i], MusicBlockType::Slowdown);
			else if (m_BombCounter % 33 == 0)
				SpawnBlock(m_Letters[i], MusicBlockType::Bomb);
			else
				SpawnBlock(m_Letters[i], MusicBlockType::Normal);

			m_Times.RemoveAt(i);
			m_Letters.RemoveAt(i);

			--i;
		}
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