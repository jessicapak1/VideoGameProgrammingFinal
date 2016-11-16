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
	// Sets default values for this character's properties
	AStationaryDuckCharacter();
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
    void DestroyDuck();
private:
	
	
};
