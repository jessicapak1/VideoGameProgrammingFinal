// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "DuckHuntersGameMode.generated.h"

UCLASS(minimalapi)
class ADuckHuntersGameMode : public AGameMode
{
	GENERATED_BODY()

		void BeginPlay() override;
public:
	ADuckHuntersGameMode();

	int mScore;
	float mTimer;

};



