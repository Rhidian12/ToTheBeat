// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MusicBlock.h"
#include "SlowmotionBlock.generated.h"

/**
 * 
 */
UCLASS()
class TOTHEBEAT_API ASlowmotionBlock : public AMusicBlock
{
	GENERATED_BODY()
	

public:


protected:
	virtual void Tick(float DeltaTime) override;

private:
};
