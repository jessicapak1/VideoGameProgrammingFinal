// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DuckAIController.h"
#include "StationaryDuckAIController.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API AStationaryDuckAIController : public ADuckAIController
{
	GENERATED_BODY()
public:
	AStationaryDuckAIController();
	void BeginPlay() override;
	void Tick(float deltaTime) override;
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	void Appear();
private:
	enum class StationaryDuckState
	{
		Start,
		Appear,
		Dead
	};
	StationaryDuckState mCurrentState;
	float mRange;
	
	
	
};
