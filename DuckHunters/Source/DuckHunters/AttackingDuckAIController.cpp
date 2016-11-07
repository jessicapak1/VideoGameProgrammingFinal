// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "AttackingDuckAIController.h"
#include "AttackingDuckCharacter.h"


AAttackingDuckAIController::AAttackingDuckAIController()
{
	mRange = 150.0f;
}

void AAttackingDuckAIController::BeginPlay()
{
	Super::BeginPlay();
	mCurrentState = AttackingDuckState::Start;
}

void AAttackingDuckAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	if (mCurrentState == AttackingDuckState::Start)
	{
		ChasePlayer();
	}
	else if (mCurrentState == AttackingDuckState::Attack)
	{
		APawn* pawn = UGameplayStatics::GetPlayerPawn(this, 0); // player
		AAttackingDuckCharacter* duckPawn = Cast<AAttackingDuckCharacter>(GetPawn()); // attacking duck

																	   // distance from player to attacking duck
		if (duckPawn != nullptr && pawn != nullptr)
		{
			float rangeDistance = FVector::Dist(duckPawn->GetActorLocation(), pawn->GetActorLocation());

			if (rangeDistance > mRange) // out of range so chase player & stop attacking
			{
				duckPawn->StopAttack();
				ChasePlayer();
			}
		}
	}
}

void AAttackingDuckAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	if (Result == EPathFollowingResult::Success)
	{
		mCurrentState = AttackingDuckState::Attack;
		AAttackingDuckCharacter* duckPawn = Cast<AAttackingDuckCharacter>(GetPawn()); // duck
		if (duckPawn != nullptr)
		{
			duckPawn->StartAttack();
		}
	}
}


void AAttackingDuckAIController::ChasePlayer()
{
	APawn* pawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (pawn != nullptr)
	{
		MoveToActor(pawn);
		mCurrentState = AttackingDuckState::Chase;
	}
}
