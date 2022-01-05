// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "MusicBlock.h"
#include "MusicBlockManager.generated.h"

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	TArray<AMusicBlock*> m_MusicBlocks;
};