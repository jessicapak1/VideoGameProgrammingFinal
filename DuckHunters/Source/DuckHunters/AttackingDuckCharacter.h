// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DuckCharacter.h"
#include "AttackingDuckCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API AAttackingDuckCharacter : public ADuckCharacter
{
	GENERATED_BODY()
	
public:
	AAttackingDuckCharacter();
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void StartAttack();
	void StopAttack();
	void AttackPlayer();
    void DestroyDuck();
	
private:

	FTimerHandle mAttackTimer;
};
