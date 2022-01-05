// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockSpawner.h"
#include "ToTheBeatGameInstance.h"
#include "MusicBlockManager.h"
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
}

// Called when the game starts or when spawned
void AMusicBlockSpawner::BeginPlay()
{
	Super::BeginPlay();

	FString path{ FPaths::ProjectContentDir() };
	path.Append("SongBeats/Undertale - Megalovania.txt");

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	FString fileContent;
	if (FileManager.FileExists(*path))
	{
		if (FFileHelper::LoadFileToString(fileContent, *path, FFileHelper::EHashOptions::None))
		{
			//UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *fileContent);
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

		if (newLineLocation != INDEX_NONE)
		{
			FString line{ fileContent.Mid(i, newLineLocation - i) };

			// UE_LOG(LogTemp, Warning, TEXT("Line %i :, %s"), i, *line);

			if (line.Find(TEXT("#"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, -1) == INDEX_NONE)
			{
				const int32 spacePos{ line.Find(TEXT(" "), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, -1) };

				if (spacePos != INDEX_NONE)
				{
					const FString time{ line.Mid(0, spacePos) };
					const FString letter{ line.Mid(spacePos + 1, 1) };

					m_Letters.Add(letter[0]);
					m_Times.Add(FCString::Atof(*time));
				}
			}

			i = newLineLocation + 1;
		}
		else
			++i;
	}

	m_InversePlayerForward = -GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector();
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
			if (m_SlowdownCounter++ % 10 != 0)
				SpawnBlock(m_Letters[i], MusicBlockType::Normal);
			else
				SpawnBlock(m_Letters[i], MusicBlockType::Slowdown);

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

	static_cast<AMusicBlock*>(pActor)->SetDirection(m_InversePlayerForward);
	static_cast<AMusicBlock*>(pActor)->SetText(FText::FromString(text));
	static_cast<UStaticMeshComponent*>(pActor->GetComponentByClass(UStaticMeshComponent::StaticClass()))->SetMaterial(0, pMaterial);

	pMusicBlockManager->AddMusicBlock(static_cast<AMusicBlock*>(pActor));
}