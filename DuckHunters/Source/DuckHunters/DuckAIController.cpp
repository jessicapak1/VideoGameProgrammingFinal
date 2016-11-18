// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckAIController.h"
#include "DuckCharacter.h"
#include <iostream>

ADuckAIController::ADuckAIController()
{
	std::cout << "inside duck AI " << std::endl;
}

void ADuckAIController::BeginPlay()
{
	Super::BeginPlay();
	mCurrentState = DuckState::Start;
}

void ADuckAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (mCurrentState == DuckState::Start)
	{
        //DoAction();
	}
	else if (mCurrentState == DuckState::DoAction)
	{
		APawn* pawn = UGameplayStatics::GetPlayerPawn(this, 0); // player
		ADuckCharacter* duckPawn = Cast<ADuckCharacter>(GetPawn()); // dwarf

		// Fly Around... on a spline
       // DoAction();
	}
}

void ADuckAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	if (Result == EPathFollowingResult::Success)
	{
		mCurrentState = DuckState::DoAction;
		ADuckCharacter* duckPawn = Cast<ADuckCharacter>(GetPawn()); // dwarf
		if (duckPawn != nullptr)
		{
			// ??
            //DoAction();
		}
	}
}


