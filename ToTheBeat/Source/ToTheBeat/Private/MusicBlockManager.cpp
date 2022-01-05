// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockManager.h"
#include "ToTheBeatGameInstance.h"
#include "MusicBlock.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AMusicBlockManager::AMusicBlockManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMusicBlockManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMusicBlockManager::AddMusicBlock(AMusicBlock* const pMusicBlock) noexcept
{
	m_MusicBlocks.Add(pMusicBlock);
}

void AMusicBlockManager::RemoveMusicBlockByValue(AMusicBlock* const pMusicBlock) noexcept
{
	const int32 index{ m_MusicBlocks.Find(pMusicBlock) };

	if (index < m_MusicBlocks.Num())
	{
		m_MusicBlocks[index]->Destroy();
		m_MusicBlocks.RemoveAt(index);
	}
}

void AMusicBlockManager::RemoveMusicBlockByIndex(const int index) noexcept
{
	if (index < m_MusicBlocks.Num())
	{
		m_MusicBlocks[index]->Destroy();
		m_MusicBlocks.RemoveAt(index);
	}
}

void AMusicBlockManager::TryToDestroyBlock(const char c) noexcept
{
	/* [TODO] Get Reference to scoring system in here to adjust score */
	/* [TODO] Get Reference to health system to remove health if necessary */

	const FText& musicBlockText{ m_MusicBlocks[0]->GetText() };
	bool wasPlayerCorrect{};

	switch (c)
	{
	case 'W':
		if (musicBlockText.EqualTo(FText::FromString(TEXT("W"))))
			wasPlayerCorrect = true;
		break;
	case 'A':
		if (musicBlockText.EqualTo(FText::FromString(TEXT("A"))))
			wasPlayerCorrect = true;
		break;
	case 'S':
		if (musicBlockText.EqualTo(FText::FromString(TEXT("S"))))
			wasPlayerCorrect = true;
		break;
	case 'D':
		if (musicBlockText.EqualTo(FText::FromString(TEXT("D"))))
			wasPlayerCorrect = true;
		break;
	}

	if (wasPlayerCorrect)
	{
		/* [TODO] Increase score */
		RemoveMusicBlockByIndex(0);
	}
	else
	{
		/* Decrease lives, but dont remove the block! */
	}
}

void AMusicBlockManager::Tick(float DeltaTime)
{
	/* make sure the first block has the emissive material */

	UMaterialInterface* pMaterialInterface{ m_MusicBlocks[0]->GetStaticMeshComponent()->GetMaterial(0) };
	if (pMaterialInterface->GetMaterial()->GetName() != TEXT("MAT_EmissiveSolidColor"))
	{
		UToTheBeatGameInstance* const pGameInstance{ static_cast<UToTheBeatGameInstance*>(UGameplayStatics::GetGameInstance(GetWorld())) };
		const UMaterialManager* const pMaterialManager{ pGameInstance->GetMaterialManagerInstance() };

		const int32 index{ pMaterialManager->GetIndexByMaterial(pMaterialInterface) };

		if (index != INDEX_NONE)
			m_MusicBlocks[0]->GetStaticMeshComponent()->SetMaterial(0, pMaterialManager->GetMaterial(index + 4));
	}
}