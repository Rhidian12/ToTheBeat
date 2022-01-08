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

	void ReadFile() noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Transform for block to spawn"))
	void AddTransform(const FTransform& transform) noexcept;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetSpawnDelay"))
	void SetDelay(const float delay) noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SpawnBlock(const char c, const MusicBlockType type) const noexcept;
	// bool IsTrack(const FString& fileContents);
	float GetCrotchet(const FString& line) const noexcept;

	int32 FindByPredicate(const FString& fstring, bool (*predicate)(const TCHAR), const int32 startPos = 0) const noexcept;
	bool AreEqual(const float a, const float b) const noexcept;

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

	int m_SlowdownCounter;
	int m_BombCounter;

	UPROPERTY(EditAnywhere)
	TArray<int32> m_Tracks;

	UPROPERTY(EditAnywhere)
	FString m_FileBeats;

	UPROPERTY(EditAnywhere)
	FString m_FileLetters;

	UPROPERTY(EditAnywhere)
	float m_BPM;
};
