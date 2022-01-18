// Fill out your copyright notice in the Description page of Project Settings.


#include "ToTheBeatGameInstance.h"

#include "UMaterialManager.h"
#include "MusicBlockManager.h"
#include "ScoreManager.h"
#include "ModelManager.h"

UMaterialManager* UToTheBeatGameInstance::GetMaterialManagerInstance() noexcept
{
	return IsValid(m_pMaterialManagerInstance) ?
		m_pMaterialManagerInstance :
		m_pMaterialManagerInstance = NewObject<UMaterialManager>(this, FName{ "Material Manager" });
}

AMusicBlockManager* UToTheBeatGameInstance::GetMusicBlockManagerInstance() noexcept
{
	return IsValid(m_pMusicBlockManagerInstance) ?
		m_pMusicBlockManagerInstance : nullptr;
		// m_pMusicBlockManagerInstance = Cast<AMusicBlockManager>(GetWorld()->SpawnActor(AMusicBlockManager::StaticClass()));
}

UScoreManager* UToTheBeatGameInstance::GetScoreManagerInstance() noexcept
{
	return IsValid(m_pScoreManagerInstance) ?
		m_pScoreManagerInstance :
		m_pScoreManagerInstance = NewObject<UScoreManager>(this, FName{ "Score Manager" });
}

UModelManager* UToTheBeatGameInstance::GetModelManagerInstance() noexcept
{
	return IsValid(m_pModelManagerInstance) ?
		m_pModelManagerInstance : nullptr;
		/*m_pModelManagerInstance = NewObject<UModelManager>(this, FName{ "Model Manager" });*/
}

void UToTheBeatGameInstance::Shutdown()
{
	UGameInstance::Shutdown();
}

void UToTheBeatGameInstance::SetModelManagerInstance(UModelManager* const pModelManagerInstance) noexcept
{
	m_pModelManagerInstance = pModelManagerInstance;
}

void UToTheBeatGameInstance::SetMusicBlockManagerInstance(AMusicBlockManager* const pMusicBlockManager) noexcept
{
	m_pMusicBlockManagerInstance = pMusicBlockManager;
}