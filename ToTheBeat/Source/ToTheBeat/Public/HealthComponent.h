// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOTHEBEAT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void IncreaseHealth(const int hp) noexcept;
	void DecreaseHealth(const int hp) noexcept;

	int GetMaxHealth() const noexcept;
	int GetCurrentHealth() const noexcept;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	int m_MaxHealth;
	int m_CurrentHealth;
};
