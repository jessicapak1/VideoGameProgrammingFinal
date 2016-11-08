// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "StationaryDuckCharacter.h"
#include "StationaryDuckAIController.h"

AStationaryDuckCharacter::AStationaryDuckCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AStationaryDuckAIController::StaticClass();
	mDuckHealth = 20.0f;
	mDuckDamage = 0.0f;
}

float AStationaryDuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.0f)
	{
		mDuckHealth -= ActualDamage;
		if (mDuckHealth <= 0.0f)
		{
			// We're dead, don't allow further damage
			bCanBeDamaged = false;
			// TODO: Process death
			float duration = PlayAnimMontage(DeathAnim);
			GetWorldTimerManager().SetTimer(mDeathTimer, this, &ADuckCharacter::DestroyDuck, duration - 0.25f, true);
			GetController()->UnPossess();
		}
	}
	return ActualDamage;
}
