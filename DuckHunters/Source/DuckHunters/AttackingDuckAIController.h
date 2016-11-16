// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DuckAIController.h"
#include "AttackingDuckAIController.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API AAttackingDuckAIController : public ADuckAIController
{
	GENERATED_BODY()
public:
	AAttackingDuckAIController();
	void BeginPlay() override;
	void Tick(float deltaTime) override;
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	void ChasePlayer();
	//void DoAction() override;
private:
	enum class AttackingDuckState
	{
		Start,
		Chase,
		Attack,
		Dead
	};
	AttackingDuckState mCurrentState;
	float mRange;
	
	
	
};
