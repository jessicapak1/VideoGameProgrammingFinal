// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DuckCharacter.h"
#include "StationaryDuckCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API AStationaryDuckCharacter : public ADuckCharacter
{
	GENERATED_BODY()


public:
	void BeginPlay() override;
	void DestroyDuck();


	float AStationaryDuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser) override; 
private:
	
	TSubobjectPtrDeprecated<UStaticMeshComponent> StaticMeshComponent; 

	UStaticMesh * Chair1;
};
