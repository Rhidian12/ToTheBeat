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

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Static Mesh"))
	void AddStaticMesh(const FString& id, UStaticMesh* pStaticMesh) noexcept;

	UStaticMesh* const GetMesh(const FString& id) const noexcept;

protected:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TMap<FString, UStaticMesh*> m_Meshes;
};	