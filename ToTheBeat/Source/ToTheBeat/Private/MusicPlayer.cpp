// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicPlayer.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AMusicPlayer::AMusicPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMusicPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	// m_pAudioComponent->Play();
	UGameplayStatics::PlaySound2D(this, m_pAudio);
}

// Called every frame
void AMusicPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

