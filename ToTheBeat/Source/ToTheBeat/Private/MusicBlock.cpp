// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlock.h"
#include "ToTheBeatGameInstance.h"
#include "ModelManager.h"


// Sets default values
AMusicBlock::AMusicBlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	// m_pStaticMeshComponent->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object);

	RootComponent = m_pStaticMeshComponent;

	m_pTextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComponent");
	m_pTextRenderComponent->TextRenderColor = FColor::White;

	m_pTextRenderComponent->SetupAttachment(RootComponent);

	m_Direction = FVector{};

	m_IsDataSet = false;

	m_MusicBlockType = MusicBlockType::Normal;
}

// Called when the game starts or when spawned
void AMusicBlock::BeginPlay()
{
	Super::BeginPlay();

	m_MaxSpeed = 150.f;
	m_CurrentSpeed = m_MaxSpeed;

	RootComponent->SetMobility(EComponentMobility::Type::Movable);

	SetActorScale3D(FVector{ 0.5f, 0.5f, 0.5f });

	m_pStaticMeshComponent->SetStaticMesh(Cast<UToTheBeatGameInstance>(GetWorld()->GetGameInstance())->GetModelManagerInstance()->GetMesh(TEXT("Cube")));
}

// Called every frame
void AMusicBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RootComponent->MoveComponent(m_Direction * m_CurrentSpeed * DeltaTime, GetActorRotation().Quaternion(), false);
}

void AMusicBlock::SetDirection(const FVector& direction) noexcept
{
	m_Direction = direction;
}

void AMusicBlock::SetText(const FText& text) noexcept
{
	m_pTextRenderComponent->SetText(text);
}

void AMusicBlock::SetMusicBlockType(const MusicBlockType type) noexcept
{
	m_MusicBlockType = type;
}

void AMusicBlock::SetCurrentSpeed(const float currentSpeed) noexcept
{
	m_CurrentSpeed = currentSpeed;
}

const FText& AMusicBlock::GetText() const noexcept
{
	return m_pTextRenderComponent->Text;
}

UStaticMeshComponent* const AMusicBlock::GetStaticMeshComponent() const noexcept
{
	return m_pStaticMeshComponent;
}

MusicBlockType AMusicBlock::GetMusicBlockType() const noexcept
{
	return m_MusicBlockType;
}

float AMusicBlock::GetMaxSpeed() const noexcept
{
	return m_MaxSpeed;
}