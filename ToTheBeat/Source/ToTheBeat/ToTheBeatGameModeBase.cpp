// Copyright Epic Games, Inc. All Rights Reserved.


#include "ToTheBeatGameModeBase.h"
#include "PlayerPawn.h"

AToTheBeatGameModeBase::AToTheBeatGameModeBase()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
}