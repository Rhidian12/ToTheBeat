// Fill out your copyright notice in the Description page of Project Settings.


#include "ToTheBeatGameInstance.h"

UMaterialManager* UToTheBeatGameInstance::GetMaterialManagerInstance() noexcept
{
	return IsValid(m_pMaterialManagerInstance) ?
		m_pMaterialManagerInstance :
		m_pMaterialManagerInstance = NewObject<UMaterialManager>(this, FName("Material Manager"));
}

void UToTheBeatGameInstance::Shutdown()
{
	UGameInstance::Shutdown();
}