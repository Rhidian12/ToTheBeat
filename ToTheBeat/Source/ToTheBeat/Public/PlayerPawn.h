// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include <Components/StaticMeshComponent.h>
#include <Components/InputComponent.h>
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "PlayerPawn.generated.h"

class UHealthComponent;

UCLASS()
class TOTHEBEAT_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UHealthComponent* const GetHealthComponent() const noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void WPressed();
	void APressed();
	void SPressed();
	void DPressed();

private:
	UStaticMeshComponent* m_pStaticMeshComponent;
	USpringArmComponent* m_pSpringArmComponent;
	UCameraComponent* m_pCameraComponent;
	UHealthComponent* m_pHealthComponent;
};
