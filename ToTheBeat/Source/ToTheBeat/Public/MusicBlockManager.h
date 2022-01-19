// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "MusicBlock.h"
#include "MusicBlockManager.generated.h"

class APlayerPawn;

/**
 * 
 */
UCLASS(Blueprintable)
class TOTHEBEAT_API AMusicBlockManager : public AActor
{
	GENERATED_BODY()
	

public:
	AMusicBlockManager();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Music Block"))
	void AddMusicBlock(AMusicBlock* const pMusicBlock) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Remove Music Block By Value"))
	void RemoveMusicBlockByValue(AMusicBlock* const pMusicBlock) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Remove Music Block By Index"))
	void RemoveMusicBlockByIndex(const int index) noexcept;

	void TryToDestroyBlock(const char c) noexcept;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Slowdown Time"))
	float GetSlowdownTime() const noexcept;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Have all MusicBlocks been destroyed"))
	bool HaveAllNotesBeenDestroyed() const noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Was a Bomb destroyed this frame"))
	bool WasBombDestroyed() const noexcept;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is the Slowdown active"))
	bool IsSlowdownActive() const noexcept;

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get the Destroyed Bomb's location"))
	FTransform GetBombTransform() const noexcept;

private:
	void ApplyEmissiveMaterialToFirstBlock() noexcept;
	void HandleSlowdown(const float DeltaTime) noexcept;
	void HandleBomb() noexcept;

	TArray<AMusicBlock*> m_MusicBlocks;

	bool m_IsSlowdownActive;
	float m_SlowdownTime;
	float m_SlowdownTimer;

	bool m_WasBombActivated;
	int m_AmountOfBlocksDestroyedByBomb;

	APlayerPawn* m_pPlayerPawn;

	bool m_WasBombDestroyed;
	FTransform m_BombTransform;
	int m_WrongInputs;

	UPROPERTY(EditAnywhere)
	USoundCue* m_pBlockDestructionSound;
};