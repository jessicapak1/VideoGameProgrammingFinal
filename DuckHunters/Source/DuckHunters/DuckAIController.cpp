// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckAIController.h"

ADuckAIController::ADuckAIController()
{

}

void ADuckAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ADuckAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void ADuckAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{

}
