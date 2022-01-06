// Fill out your copyright notice in the Description page of Project Settings.


#include "ModelManager.h"

UModelManager::UModelManager()
{
	m_Meshes.Add(TTuple<FString, UStaticMesh*>{ FString{ TEXT("Cube") },
		ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object });
}

void UModelManager::AddStaticMesh(const FString& id, UStaticMesh* pStaticMesh) noexcept
{
	m_Meshes.Add(TTuple<FString, UStaticMesh*>{ id, pStaticMesh });
}

UStaticMesh* const UModelManager::GetMesh(const FString& id) const noexcept
{
	return m_Meshes.FindRef(id);
}