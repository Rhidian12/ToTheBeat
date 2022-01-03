// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/AudioComponent.h>

#include "MusicPlayer.generated.h"

UCLASS()
class TOTHEBEAT_API AMusicPlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicPlayer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetAudioDelay"))
	void SetDelay(const float delay) noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"));
	USoundBase* m_pAudio;

	float m_Delay;
	float m_DelayTimer;
	bool m_IsDelaySet;
	bool m_IsAudioPlaying;
};
