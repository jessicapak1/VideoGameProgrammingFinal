// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "DuckHunters.h"
#include "DuckHuntersGameMode.h"
#include "DuckHuntersHUD.h"
#include "DuckHuntersCharacter.h"

ADuckHuntersGameMode::ADuckHuntersGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADuckHuntersHUD::StaticClass();
}
