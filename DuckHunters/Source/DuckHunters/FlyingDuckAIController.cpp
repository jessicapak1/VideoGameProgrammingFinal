// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "FlyingDuckAIController.h"
#include "FlyingDuckCharacter.h"

AFlyingDuckAIController::AFlyingDuckAIController()
{
	mRange = 100.0f;
}

void AFlyingDuckAIController::BeginPlay()
{
	Super::BeginPlay();
	mCurrentState = FlyingDuckState::Start;
}

void AFlyingDuckAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (mCurrentState == FlyingDuckState::Start)
	{
		FlyAround();
	}
	else if (mCurrentState == FlyingDuckState::Fly)
	{
		APawn* pawn = UGameplayStatics::GetPlayerPawn(this, 0); // player
		AFlyingDuckCharacter* duckPawn = Cast<AFlyingDuckCharacter>(GetPawn()); // dwarf

		// Fly Around... on a spline
	}
}

void AFlyingDuckAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	if (Result == EPathFollowingResult::Success)
	{
		mCurrentState = FlyingDuckState::Fly;
		AFlyingDuckCharacter* duckPawn = Cast<AFlyingDuckCharacter>(GetPawn()); // dwarf
		if (duckPawn != nullptr)
		{
			// ?? 
		}
	}
}

void AFlyingDuckAIController::FlyAround()
{
}
