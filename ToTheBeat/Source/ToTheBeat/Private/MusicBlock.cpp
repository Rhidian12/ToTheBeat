// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlock.h"

// Sets default values
AMusicBlock::AMusicBlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	m_pStaticMeshComponent->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object);

	RootComponent = m_pStaticMeshComponent;

	m_pTextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComponent");
	m_pTextRenderComponent->TextRenderColor = FColor::White;
	
	m_pTextRenderComponent->SetupAttachment(RootComponent);

	m_Direction = FVector{};

	m_IsDataSet = false;
}

// Called when the game starts or when spawned
void AMusicBlock::BeginPlay()
{
	Super::BeginPlay();

	m_Speed = 250.f;

	RootComponent->SetMobility(EComponentMobility::Type::Movable);

	SetActorScale3D(FVector{ 0.5f, 0.5f, 0.5f });
}

// Called every frame
void AMusicBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Direction: %f, %f, %f"), m_Direction.X, m_Direction.Y, m_Direction.Z);

	RootComponent->MoveComponent(m_Direction * m_Speed * DeltaTime, GetActorRotation().Quaternion(), false);
}

void AMusicBlock::SetDirection(const FVector& direction) noexcept
{
	m_Direction = direction;
}

void AMusicBlock::SetText(const FText& text) noexcept
{
	m_pTextRenderComponent->SetText(text);
}