// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "SpawnManager.h"
#include "Engine/TargetPoint.h"
#include "StationaryDuckCharacter.h"
#include "FlyingDuckCharacter.h"
#include "AttackingDuckCharacter.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnTime = 5.0f;
}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(mSpawnTimer, this, &ASpawnManager::OnSpawnTimer, SpawnTime, true);
}

// Called every frame
void ASpawnManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASpawnManager::OnSpawnTimer()
{
	int numOfElements = SpawnPoints.Num();
	if (numOfElements != 0)
	{
		int index = FMath::RandRange(0, numOfElements - 1);
		ATargetPoint* target = SpawnPoints[index];
		FVector location = target->GetActorLocation();
		FRotator rotation = target->GetActorRotation();

		// Spawn an ACharacter of subclass CharacterClass, at specified position and rotation
		//ACharacter* Char = GetWorld()->SpawnActor<ACharacter>(CharacterClass, location, rotation);
		AAttackingDuckCharacter* attacking = GetWorld()->SpawnActor<AAttackingDuckCharacter>(CharacterClass, location, rotation);
		/*
		AStationaryDuckCharacter* stationary = GetWorld()->SpawnActor<AStationaryDuckCharacter>(CharacterClass, location, rotation);
		AFlyingDuckCharacter* flying = GetWorld()->SpawnActor<AFlyingDuckCharacter>(CharacterClass, location, rotation);

		if (stationary)
		{
			// Spawn the AI controller for stationary character
			stationary->SpawnDefaultController();
		}

		if (flying)
		{
			// Spawn the AI controller for flying character
			flying->SpawnDefaultController();
		}
		*/
		if (attacking)
		{
			// Spawn the AI controller for attacking character
			attacking->SpawnDefaultController();
		}
	}
}