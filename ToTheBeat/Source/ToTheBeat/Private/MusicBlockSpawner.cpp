// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockSpawner.h"

// Sets default values
AMusicBlockSpawner::AMusicBlockSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FJsonSerializableArray fileContents{};
	FFileHelper::LoadFileToStringArray(fileContents, TEXT("SongBeats/Undertale - Megalovania.txt"));

	for (const auto& element : fileContents)
		UE_LOG(LogTemp, Warning, TEXT("%s"), element);
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