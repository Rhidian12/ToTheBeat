// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ToTheBeatGameInstance.h"
#include "HealthComponent.h"
#include "MusicBlockManager.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	m_pStaticMeshComponent->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'")).Object);

	RootComponent = m_pStaticMeshComponent;

	m_pSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	m_pSpringArmComponent->TargetArmLength = -100.f;

	m_pCameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	m_pCameraComponent->SetupAttachment(m_pSpringArmComponent);

	m_pSpringArmComponent->SetupAttachment(RootComponent);

	m_pHealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
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

	PlayerInputComponent->BindAction("W", EInputEvent::IE_Released, this, &APlayerPawn::WPressed);
	PlayerInputComponent->BindAction("A", EInputEvent::IE_Released, this, &APlayerPawn::APressed);
	PlayerInputComponent->BindAction("S", EInputEvent::IE_Released, this, &APlayerPawn::SPressed);
	PlayerInputComponent->BindAction("D", EInputEvent::IE_Released, this, &APlayerPawn::DPressed);
}

UHealthComponent* const APlayerPawn::GetHealthComponent() const noexcept
{
	return m_pHealthComponent;
}

void APlayerPawn::WPressed()
{
	static_cast<UToTheBeatGameInstance*>(UGameplayStatics::GetGameInstance(GetWorld()))->GetMusicBlockManagerInstance()->TryToDestroyBlock('W');
}

void APlayerPawn::APressed()
{
	static_cast<UToTheBeatGameInstance*>(UGameplayStatics::GetGameInstance(GetWorld()))->GetMusicBlockManagerInstance()->TryToDestroyBlock('A');
}

void APlayerPawn::SPressed()
{
	static_cast<UToTheBeatGameInstance*>(UGameplayStatics::GetGameInstance(GetWorld()))->GetMusicBlockManagerInstance()->TryToDestroyBlock('S');
}

void APlayerPawn::DPressed()
{
	static_cast<UToTheBeatGameInstance*>(UGameplayStatics::GetGameInstance(GetWorld()))->GetMusicBlockManagerInstance()->TryToDestroyBlock('D');
}