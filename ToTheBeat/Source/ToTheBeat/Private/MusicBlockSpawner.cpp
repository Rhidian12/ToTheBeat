// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockSpawner.h"

// Sets default values
AMusicBlockSpawner::AMusicBlockSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
}

// Called every frame
void AMusicBlockSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMusicBlockSpawner::AddMaterial(UMaterial* const pMaterial) noexcept
{
	m_pMaterials.Add(pMaterial);
}