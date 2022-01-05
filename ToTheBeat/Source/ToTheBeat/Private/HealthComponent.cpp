// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	m_MaxHealth = 100;
	m_CurrentHealth = m_MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::IncreaseHealth(const int hp) noexcept
{
	m_CurrentHealth += hp;

	if (m_CurrentHealth >= m_MaxHealth)
		m_CurrentHealth = m_MaxHealth;
}

void UHealthComponent::DecreaseHealth(const int hp) noexcept
{
	m_CurrentHealth -= hp;

	if (m_CurrentHealth < 0)
		m_CurrentHealth = 0;
}

int UHealthComponent::GetMaxHealth() const noexcept
{
	return m_MaxHealth;
}

int UHealthComponent::GetCurrentHealth() const noexcept
{
	return m_CurrentHealth;
}