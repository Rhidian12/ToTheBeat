// Fill out your copyright notice in the Description page of Project Settings.


#include "ToTheBeatGameInstance.h"

UMaterialManager* UToTheBeatGameInstance::GetMaterialManagerInstance() noexcept
{
	return IsValid(m_pMaterialManagerInstance) ?
		m_pMaterialManagerInstance :
		m_pMaterialManagerInstance = NewObject<UMaterialManager>(this, FName("Material Manager"));
}

UMusicBlockManager* UToTheBeatGameInstance::GetMusicBlockManagerInstance() noexcept
{
	return IsValid(m_pMusicBlockManagerInstance) ?
		m_pMusicBlockManagerInstance :
		m_pMusicBlockManagerInstance = NewObject<UMusicBlockManager>(this, FName("MusicBlock Manager"));
}

void UToTheBeatGameInstance::Shutdown()
{
	UGameInstance::Shutdown();
}