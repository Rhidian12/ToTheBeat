// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "ToTheBeatGameInstance.generated.h"

class UMaterialManager;
class AMusicBlockManager;
class UScoreManager;
class UModelManager;
class AMusicPlayer;

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

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get MusicPlayer Instance"))
	AMusicPlayer* GetMusicPlayerInstance() noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set ModelManager Instance"))
	void SetModelManagerInstance(UModelManager* const pModelManagerInstance) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set MusicBlockManager Instance"))
	void SetMusicBlockManagerInstance(AMusicBlockManager* const pMusicBlockManager) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set MusicPlayer Instance"))
	void SetMusicPlayerInstance(AMusicPlayer* const pMusicPlayer) noexcept;

protected:
	virtual void Shutdown() override;

	/* this needs to be UPROPERTY so GC does its thing (apparently) */
	/* Transient so that the object does not get serialized */
	UPROPERTY(Transient)
	UMaterialManager* m_pMaterialManagerInstance;

	UPROPERTY(Transient)
	AMusicBlockManager* m_pMusicBlockManagerInstance;

	UPROPERTY(Transient)
	UScoreManager* m_pScoreManagerInstance;

	UPROPERTY(Transient)
	UModelManager* m_pModelManagerInstance;

	UPROPERTY(Transient)
	AMusicPlayer* m_pMusicPlayerInstance;
};
