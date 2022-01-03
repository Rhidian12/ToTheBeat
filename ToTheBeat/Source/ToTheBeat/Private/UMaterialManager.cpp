// Fill out your copyright notice in the Description page of Project Settings.


#include "UMaterialManager.h"

UMaterialManager::UMaterialManager()
{
}

UMaterialManager::~UMaterialManager()
{
}

void UMaterialManager::AddMaterial(UMaterialInterface* const pMaterial) noexcept
{
	m_Materials.Add(pMaterial);
}

UMaterialInterface* UMaterialManager::GetMaterial(const int index) const noexcept
{
	return m_Materials[index];
}