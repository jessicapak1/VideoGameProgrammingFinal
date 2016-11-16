// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "DuckHuntersGameMode.generated.h"

UCLASS(minimalapi)
class ADuckHuntersGameMode : public AGameMode
{
	GENERATED_BODY()
public:
		ADuckHuntersGameMode();
		void BeginPlay() override;
		void IncrementScore();
		int GetScore() { return mScore; }
		
		void DecrementTime();
		float GetTimeRemaining() { return mTimeRemaining; }

		void PauseGame();
		void UnpauseGame();
		bool IsPaused() { return mPaused; }

private: 

	FTimerHandle mRoundTimer;
	bool mPaused;
	int mScore;
	float mTimeRemaining;

};



