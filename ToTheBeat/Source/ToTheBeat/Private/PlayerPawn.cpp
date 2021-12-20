// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actors{};
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "PlayerStart", actors);

	if (actors.Num() > 0)
	{
		auto transform{ actors[0]->GetTransform() };
		SetActorTransform(transform, false, nullptr, ETeleportType::ResetPhysics);
	}

	auto transform{ GetTransform() };
	bool b = true;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

