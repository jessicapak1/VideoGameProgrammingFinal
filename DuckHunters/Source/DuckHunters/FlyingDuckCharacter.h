// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DuckCharacter.h"
#include "FlyingDuckCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API AFlyingDuckCharacter : public ADuckCharacter
{
	GENERATED_BODY()

public:
	AFlyingDuckCharacter();
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:

	
	
};
