// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttackingDuckCharacter.h"
#include "DuckCharacter.h"
#include "StationaryDuckCharacter.h"
#include "FlyingDuckCharacter.h"
#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

UCLASS()
class DUCKHUNTERS_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	void OnSpawnTimer();

private: 
	UPROPERTY(EditAnywhere)
		TArray<class ATargetPoint*> SpawnPoints;

	UPROPERTY(EditAnywhere)
		TSubclassOf <class AAttackingDuckCharacter> AttackingDuckCharacterClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AFlyingDuckCharacter> FlyingDuckCharacterClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AStationaryDuckCharacter> StationaryDuckCharacterClass;

	UPROPERTY(EditAnywhere)
		float SpawnTime;
	FTimerHandle mSpawnTimer;
	
};
