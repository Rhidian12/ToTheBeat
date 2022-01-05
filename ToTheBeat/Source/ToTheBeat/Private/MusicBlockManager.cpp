// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockManager.h"
#include "ToTheBeatGameInstance.h"
#include "MusicBlock.h"
#include "PlayerPawn.h"
#include "HealthComponent.h"
#include "UMaterialManager.h"
#include "ScoreManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AMusicBlockManager::AMusicBlockManager()
{
	PrimaryActorTick.bCanEverTick = true;

	m_IsSlowdownActive = false;
	m_SlowdownTime = 1.5f;
	m_SlowdownTimer = 0.f;

	m_WasBombActivated = false;
	m_AmountOfBlocksDestroyedByBomb = 15;
}

void AMusicBlockManager::BeginPlay()
{
	Super::BeginPlay();

	m_pPlayerPawn = Cast<APlayerPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
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
	if (m_MusicBlocks.Num() == 0)
		return;

	const FText& musicBlockText{ m_MusicBlocks[0]->GetText() };
	bool wasPlayerCorrect{};

	UScoreManager* const pScoreManager{ Cast<UToTheBeatGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))->GetScoreManagerInstance() };

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
		const MusicBlockType type{ m_MusicBlocks[0]->GetMusicBlockType() };

		/* Before we remove the block, check if it is a power up */
		if (type != MusicBlockType::Normal)
		{
			/* Don't check for Normal since it can't happen anyway */
			switch (type)
			{
			case MusicBlockType::Slowdown:
				m_IsSlowdownActive = true;
				break;
			case MusicBlockType::Bomb:
				m_WasBombActivated = true;
				break;
			}
		}

		RemoveMusicBlockByIndex(0);

		/* Increase health by 1 */
		m_pPlayerPawn->GetHealthComponent()->IncreaseHealth(1);

		pScoreManager->m_Score += 50;
	}
	else
	{
		/* Decrease lives by 10, but dont remove the block! */
		m_pPlayerPawn->GetHealthComponent()->DecreaseHealth(10);
	}
}

void AMusicBlockManager::Tick(float DeltaTime)
{
	if (m_MusicBlocks.Num() == 0)
		return;

	/* Make sure the first block has the emissive material */
	
	ApplyEmissiveMaterialToFirstBlock();

	/* If the Slow down block was destroyed, slow down all blocks for x seconds */

	HandleSlowdown(DeltaTime);

	/* If a Bomb block was destroyed, delete the next x amount of blocks */
	
	HandleBomb();
}

void AMusicBlockManager::ApplyEmissiveMaterialToFirstBlock() noexcept
{
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

void AMusicBlockManager::HandleSlowdown(const float DeltaTime) noexcept
{
	if (m_IsSlowdownActive)
	{
		const float newSpeed{ m_MusicBlocks[0]->GetMaxSpeed() * 0.5f };

		for (AMusicBlock* const pMusicBlock : m_MusicBlocks)
			pMusicBlock->SetCurrentSpeed(newSpeed);

		/* Increment timer */

		if (m_SlowdownTimer < m_SlowdownTime)
			m_SlowdownTimer += DeltaTime;
		else
		{
			m_IsSlowdownActive = false;
			m_SlowdownTimer = 0.f;
		}
	}
	else
	{
		/* Make sure all blocks get the correct speed */

		const float maxSpeed{ m_MusicBlocks[0]->GetMaxSpeed() };

		for (AMusicBlock* const pMusicBlock : m_MusicBlocks)
			pMusicBlock->SetCurrentSpeed(maxSpeed);
	}
}

void AMusicBlockManager::HandleBomb() noexcept
{
	if (m_WasBombActivated)
	{
		for (int i{}; i < m_AmountOfBlocksDestroyedByBomb; ++i)
			RemoveMusicBlockByIndex(i);

		m_WasBombActivated = false;
	}
}