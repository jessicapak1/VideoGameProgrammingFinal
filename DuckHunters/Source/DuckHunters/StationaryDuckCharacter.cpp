// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "StationaryDuckCharacter.h"
#include "StationaryDuckAIController.h"

AStationaryDuckCharacter::AStationaryDuckCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AStationaryDuckAIController::StaticClass();
	mStationaryDuckHealth = 20.0f;
	mStationaryDuckDamage = 0.0f;
}

void AStationaryDuckCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AStationaryDuckCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AStationaryDuckCharacter::SetupPlayerInputComponent(UInputComponent * InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

float AStationaryDuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	return 0.0f;
}

void AStationaryDuckCharacter::DestroyDuck()
{
	this->Destroy();
}
