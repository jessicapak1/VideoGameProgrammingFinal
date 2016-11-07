// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "DuckAIController.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API ADuckAIController : public AAIController
{
	GENERATED_BODY()
public:

	ADuckAIController();
	void BeginPlay() override;
	void Tick(float deltaTime) override;
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;


private:
	enum class DuckState
	{
		Start,
		Appear,
		Dead
	};
	DuckState mCurrentState;
	float mRange;
	
	
	
};
