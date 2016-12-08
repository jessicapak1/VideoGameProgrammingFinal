// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "SpawnManager.h"
#include "Engine/TargetPoint.h"
#include "FlyingDuckCharacter.h"
#include "Engine.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnTime = 5.0f;
	//AttackingDuckCharacterClass = AAttackingDuckCharacter::StaticClass();;
	//FlyingDuckCharacterClass = AFlyingDuckCharacter::StaticClass();;
	//StationaryDuckCharacterClass = AStationaryDuckCharacter::StaticClass();;
}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(mSpawnTimer, this, &ASpawnManager::OnSpawnTimer, SpawnTime);
}

// Called every frame
void ASpawnManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASpawnManager::OnSpawnTimer()
{
	int numOfElements = SpawnPoints.Num();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(SpawnPoints.Num()));
	if (numOfElements != 0)
	{
		int index = FMath::RandRange(0, numOfElements - 1);
		ATargetPoint* target = SpawnPoints[index];
		FVector location = target->GetActorLocation();
		FRotator rotation = target->GetActorRotation();

		// Spawn an ACharacter of subclass CharacterClass, at specified position and rotation
		TSubclassOf<ACharacter> CharacterClass = AStationaryDuckCharacter::StaticClass();
		AStationaryDuckCharacter* Char = GetWorld()->SpawnActor<AStationaryDuckCharacter>(CharacterClass, location, rotation);

		TArray<UStaticMeshComponent*> components;
		Char->GetComponents<UStaticMeshComponent>(components);
	//	UStaticMeshComponent* smc = components[0];
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NUMBER OF COMPONENTS");
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(components.Num()));

		if (Char)
		{
			// Spawn the AI controller for the character
			Char->SpawnDefaultController();
		}
	}
}