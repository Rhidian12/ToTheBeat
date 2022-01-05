// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UMaterialManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOTHEBEAT_API UMaterialManager : public UObject
{
	GENERATED_BODY()


public:
	UMaterialManager();
	~UMaterialManager();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Material"))
	void AddMaterial(UMaterialInterface* const pMaterial) noexcept;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Material By Index"))
	UMaterialInterface* GetMaterial(const int index) const noexcept;

	int32 GetIndexByMaterial(UMaterialInterface* const pMaterial) const noexcept;

private:
	TArray<UMaterialInterface*> m_Materials;
};
