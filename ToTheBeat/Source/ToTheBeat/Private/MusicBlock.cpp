// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlock.h"

// Sets default values
AMusicBlock::AMusicBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	m_pStaticMeshComponent->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object);

	RootComponent = m_pStaticMeshComponent;

	m_pProjectileMovementComponent->ProjectileGravityScale = 0.f;
	m_pProjectileMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void AMusicBlock::BeginPlay()
{
	Super::BeginPlay();
	
	m_PlayerPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	m_pProjectileMovementComponent->Velocity = (m_PlayerPosition - GetActorLocation()).GetUnsafeNormal() * m_Speed;

	m_pProjectileMovementComponent->UpdateComponentVelocity();
}

// Called every frame
void AMusicBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

