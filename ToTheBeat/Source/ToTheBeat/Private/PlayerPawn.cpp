// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	m_pStaticMeshComponent->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'")).Object);

	m_pSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	m_pSpringArmComponent->TargetArmLength = -100.f;
	//m_pSpringArmComponent->SetRelativeRotation(FQuat{ m_pSpringArmComponent->GetRightVector(), FMath::DegreesToRadians(50.f) });

	m_pCameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	m_pCameraComponent->SetupAttachment(m_pSpringArmComponent);

	RootComponent = m_pStaticMeshComponent;

	m_pSpringArmComponent->SetupAttachment(RootComponent);

	// SetActorRotation(FRotator{0.f, 180.f, 0.f});
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	// TArray<AActor*> actors{};
	// UGameplayStatics::GetAllActorsWithTag(GetWorld(), "PlayerStart", actors);
	// 
	// if (actors.Num() > 0)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("pos before %f %f %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
	// 	SetActorLocation(actors[0]->GetActorLocation(), false, nullptr, ETeleportType::ResetPhysics);
	// 	UE_LOG(LogTemp, Warning, TEXT("pos after %f %f %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
	// 	// SetActorRotation(FQuat{ GetActorUpVector(), FMath::DegreesToRadians(180.f) });
	// }
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

