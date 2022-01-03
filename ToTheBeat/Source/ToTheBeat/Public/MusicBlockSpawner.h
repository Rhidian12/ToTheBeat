// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/TransformVectorized.h"
#include "../Public/MusicBlock.h"

#include "MusicBlockSpawner.generated.h"

UCLASS()
class TOTHEBEAT_API AMusicBlockSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicBlockSpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Material to assign to blocks"))
	void AddMaterial(UMaterialInterface* const pMaterial) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Transform for block to spawn"))
	void AddTransform(const FTransform& transform) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetSpawnDelay"))
	void SetDelay(const float delay) noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SpawnBlock(const char c) const noexcept;

	TArray<UMaterialInterface*> m_pMaterials;
	TArray<FTransform> m_pTransforms;

	TArray<float> m_Times;
	TArray<char> m_Letters;

	float m_TotalElapsedTime;

	bool m_IsDelaySet;
	float m_Delay;
	float m_DelayTimer;

	FVector m_InversePlayerForward;

	UPROPERTY(EditAnywhere);
	TSubclassOf<AMusicBlock> m_BPMusicBlock;
};
