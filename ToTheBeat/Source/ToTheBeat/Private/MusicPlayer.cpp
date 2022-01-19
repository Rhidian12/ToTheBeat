// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicPlayer.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AMusicPlayer::AMusicPlayer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Delay = 0.f;
	m_DelayTimer = 0.f;
	m_IsDelaySet = false;
	m_IsAudioPlaying = false;

	m_pAudioComponent = CreateDefaultSubobject<UAudioComponent>("AudioComponent");
}

// Called when the game starts or when spawned
void AMusicPlayer::BeginPlay()
{
	Super::BeginPlay();

	m_pAudioComponent->Sound = m_pAudio;
}

// Called every frame
void AMusicPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_IsDelaySet)
		return;
	else
	{
		if (m_DelayTimer < m_Delay)
		{
			m_DelayTimer += DeltaTime;
			return;
		}
	}

	if (!m_IsAudioPlaying)
	{
		m_pAudioComponent->Play();
		// UGameplayStatics::PlaySound2D(this, m_pAudio);
		m_IsAudioPlaying = true;
	}
}

void AMusicPlayer::SetDelay(const float delay) noexcept
{
	m_Delay = delay;

	m_IsDelaySet = true;
}

USoundBase* const AMusicPlayer::GetAudio() const noexcept
{
	return m_pAudio;
}

UAudioComponent* const AMusicPlayer::GetAudioComponent() const noexcept
{
	return m_pAudioComponent;
}