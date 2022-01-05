// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UMaterialManager.h"
#include "MusicBlockManager.h"
#include "ToTheBeatGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TOTHEBEAT_API UToTheBeatGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Material Manager Instance"))
	UMaterialManager* GetMaterialManagerInstance() noexcept;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get MusicBlock Manager Instance"))
	AMusicBlockManager* GetMusicBlockManagerInstance() noexcept;

protected:
	virtual void Shutdown() override;

private:
	/* this needs to be UPROPERTY so GC does its thing (apparently) */
	/* Transient so that the object does not get serialized */
	UPROPERTY(Transient)
	UMaterialManager* m_pMaterialManagerInstance;

	UPROPERTY(Transient)
	AMusicBlockManager* m_pMusicBlockManagerInstance;
};
