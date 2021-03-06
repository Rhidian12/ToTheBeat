// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/TextRenderComponent.h>

#include "MusicBlock.generated.h"

UENUM()
enum class MusicBlockType
{
	Normal,
	Slowdown,
	Bomb
};

UCLASS()
class TOTHEBEAT_API AMusicBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicBlock();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetDirection(const FVector& direction) noexcept;
	void SetText(const FText& text) noexcept;
	void SetMusicBlockType(const MusicBlockType type) noexcept;
	void SetCurrentSpeed(const float currentSpeed) noexcept;

	const FText& GetText() const noexcept;
	UStaticMeshComponent* const GetStaticMeshComponent() const noexcept;
	MusicBlockType GetMusicBlockType() const noexcept;
	float GetMaxSpeed() const noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UStaticMeshComponent* m_pStaticMeshComponent;

	UPROPERTY(EditAnywhere);
	UTextRenderComponent* m_pTextRenderComponent;

	UPROPERTY(EditAnywhere);
	float m_MaxSpeed;
	float m_CurrentSpeed;

	FVector m_Direction;
	bool m_IsDataSet;

	MusicBlockType m_MusicBlockType;
};
