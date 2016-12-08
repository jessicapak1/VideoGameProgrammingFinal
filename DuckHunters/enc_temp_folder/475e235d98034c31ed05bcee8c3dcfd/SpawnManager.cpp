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
	if (numOfElements != 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "Spawn Enemy");
		int index = FMath::RandRange(0, numOfElements - 1);
		ATargetPoint* target = SpawnPoints[index];
		FVector mLocation = target->GetActorLocation();
		FRotator mRotation = target->GetActorRotation();

		// Spawn an ACharacter of subclass CharacterClass, at specified position and rotation
		//ACharacter* Char = GetWorld()->SpawnActor<ACharacter>(CharacterClass, location, rotation);
		FTransform SpawnTM(mRotation, mLocation);
		
		//TSubclassOf<class AAttackingDuckCharacter> attackingClass = AAttackingDuckCharacter::StaticClass();
		//AAttackingDuckCharacter* attackDUCK = Cast<AAttackingDuckCharacter>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, attackingClass, SpawnTM));
	
		//AAttackingDuckCharacter* attacking = GetWorld()->SpawnActor<AAttackingDuckCharacter>(AAttackingDuckCharacter::StaticClass(), location, rotation);
		//AFlyingDuckCharacter* flying = GetWorld()->SpawnActor<AFlyingDuckCharacter>(AFlyingDuckCharacter::StaticClass(), location, rotation);
		//AStationaryDuckCharacter* stationary = GetWorld()->SpawnActor<AStationaryDuckCharacter>(AStationaryDuckCharacter::StaticClass(), mLocation, mRotation);
		
		AStationaryDuckCharacter* stationary = GetWorld()->SpawnActor<AStationaryDuckCharacter>(AStationaryDuckCharacter::StaticClass());
		
		/*TSubclassOf<class AStationaryDuckCharacter> CubeBlueprint;
		static ConstructorHelpers::FObjectFinder<UBlueprint> CubeBP(TEXT("Blueprint'/Game/BP_StationaryDuckCharacter.uasset'"));
		if (stationary) {
			CubeBlueprint = (UClass*)CubeBP.Object->GeneratedClass;
		}*/
		
		TArray<UStaticMeshComponent*> components;
		stationary->GetComponents<UStaticMeshComponent>(components);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, "Number of components AFTER");
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString::FromInt(components.Num()));
		//UStaticMeshComponent* smc = components[0];
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, smc->GetName());
		if (stationary)
		{
			// Spawn the AI controller for stationary character
			stationary->SpawnDefaultController();
			//attackDUCK->SpawnDefaultController();
		}
		/*
		if (flying)
		{
			// Spawn the AI controller for flying character
			flying->SpawnDefaultController();
		}
		
	*if (attacking)
		{
			// Spawn the AI controller for attacking character
			attacking->SpawnDefaultController();
			
		}*/
	}
}