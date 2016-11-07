// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DuckAIController.h"
#include "FlyingDuckAIController.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API AFlyingDuckAIController : public ADuckAIController
{
	GENERATED_BODY()
	
public:
	AFlyingDuckAIController();
	void BeginPlay() override;
	void Tick(float deltaTime) override;
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	void FlyAround();
private:
	enum class FlyingDuckState
	{
		Start,
		Fly,
		Dead
	};
	FlyingDuckState mCurrentState;
	float mRange;
	
	
};
