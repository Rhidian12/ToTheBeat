// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <Components/StaticMeshComponent.h>

#include "ModelManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOTHEBEAT_API UModelManager : public UObject
{
	GENERATED_BODY()


public:
	UModelManager();
	~UModelManager();

	UStaticMeshComponent* const GetMesh(const FString& id) const noexcept;

private:
	TMap<FString, UStaticMeshComponent*> m_Meshes;
};	