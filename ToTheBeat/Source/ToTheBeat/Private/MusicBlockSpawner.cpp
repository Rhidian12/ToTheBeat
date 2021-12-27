// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockSpawner.h"

// Sets default values
AMusicBlockSpawner::AMusicBlockSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	 	const int32 newLineLocation{ fileContent.Find(&FChar::NextLine, ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, i) };
	 
	 	if (newLineLocation != INDEX_NONE)
	 	{
	 		FString line{ fileContent.Mid(i, newLineLocation) };

			UE_LOG(LogTemp, Warning, TEXT("Line %i :, %s"), i, *line);
	 
	 		if (line.Find(TEXT("#"), ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, -1) != INDEX_NONE)
	 		{
	 			i = newLineLocation + 1;
	 			continue;
	 		}
	 		else
	 		{
	 			
	 			UE_LOG(LogTemp, Warning, TEXT(""), *line);
	 
	 			i = newLineLocation + 1;
	 		}
	 	}
	 }
}

// Called when the game starts or when spawned
void AMusicBlockSpawner::BeginPlay()
{
	Super::BeginPlay();

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