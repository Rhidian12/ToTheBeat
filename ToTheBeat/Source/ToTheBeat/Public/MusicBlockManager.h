// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MusicBlock.h"
#include "MusicBlockManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOTHEBEAT_API UMusicBlockManager : public UObject
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Music Block"))
	void AddMusicBlock(AMusicBlock* const pMusicBlock) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Remove Music Block By Value"))
	void RemoveMusicBlock(AMusicBlock* const pMusicBlock) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Remove Music Block By Index"))
	void RemoveMusicBlock(const int index) noexcept;

	void TryToDestroyBlock(const char c) noexcept;

private:
	TArray<AMusicBlock*> m_MusicBlocks;
};
