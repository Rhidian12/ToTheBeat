// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	void AddMaterial(UMaterial* const pMaterial) noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<UMaterial*> m_pMaterials;
	TArray<float> m_Times;
	TArray<char> m_Letters;
};
