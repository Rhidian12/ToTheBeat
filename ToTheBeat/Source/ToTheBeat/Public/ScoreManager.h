// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ScoreManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOTHEBEAT_API UScoreManager : public UObject
{
	GENERATED_BODY()


public:
	UScoreManager();
	~UScoreManager();

	int m_Score;
};
