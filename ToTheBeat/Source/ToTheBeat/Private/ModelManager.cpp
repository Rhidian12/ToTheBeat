// Fill out your copyright notice in the Description page of Project Settings.


#include "ModelManager.h"

UModelManager::UModelManager()
{
	FString path{ FPaths::ProjectContentDir() };
	path.Append("Models/Bomb.uasset");
	m_Meshes.Add(TTuple<FString, UStaticMeshComponent*>{ FString{ TEXT("Bomb") },
		CreateDefaultSubobject<UStaticMeshComponent>("BombMesh") })->SetStaticMesh(
			ConstructorHelpers::FObjectFinder<UStaticMesh>(*path).Object);

	m_Meshes.Add(TTuple<FString, UStaticMeshComponent*>{ FString{ TEXT("Cube") },
		CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh") })->SetStaticMesh(
			ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object);
}

UModelManager::~UModelManager()
{
}

UStaticMeshComponent* const UModelManager::GetMesh(const FString& id) const noexcept
{
	return m_Meshes.FindRef(id);
}