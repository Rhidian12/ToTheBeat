// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicBlockManager.h"

void UMusicBlockManager::AddMusicBlock(AMusicBlock* const pMusicBlock) noexcept
{
	m_MusicBlocks.Add(pMusicBlock);
}

void UMusicBlockManager::RemoveMusicBlock(AMusicBlock* const pMusicBlock) noexcept
{
	const int32 index{ m_MusicBlocks.Find(pMusicBlock) };

	if (index < m_MusicBlocks.Num())
	{
		m_MusicBlocks[index]->Destroy();
		m_MusicBlocks.RemoveAt(index);
	}
}

void UMusicBlockManager::RemoveMusicBlock(const int index) noexcept
{
	if (index < m_MusicBlocks.Num())
	{
		m_MusicBlocks[index]->Destroy();
		m_MusicBlocks.RemoveAt(index);
	}
}

void UMusicBlockManager::TryToDestroyBlock(const char c) noexcept
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
		RemoveMusicBlock(0);
	}
	else
	{
		/* Decrease lives, but dont remove the block! */
	}
}