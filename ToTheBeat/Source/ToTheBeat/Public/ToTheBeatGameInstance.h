// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "ToTheBeatGameInstance.generated.h"

class UMaterialManager;
class AMusicBlockManager;
class UScoreManager;
class UModelManager;

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

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get ScoreManager Instance"))
	UScoreManager* GetScoreManagerInstance() noexcept;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get ModelManager Instance"))
	UModelManager* GetModelManagerInstance() noexcept;

protected:
	virtual void Shutdown() override;

private:
	/* this needs to be UPROPERTY so GC does its thing (apparently) */
	/* Transient so that the object does not get serialized */
	UPROPERTY(Transient)
	UMaterialManager* m_pMaterialManagerInstance;

	UPROPERTY(Transient)
	AMusicBlockManager* m_pMusicBlockManagerInstance;

	UPROPERTY(Transient)
	UScoreManager* m_pScoreManagerInstance;

	UPROPERTY(Transient, EditAnywhere)
	UModelManager* m_pModelManagerInstance;
};
