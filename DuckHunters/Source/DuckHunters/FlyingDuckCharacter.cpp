// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "FlyingDuckCharacter.h"
#include "FlyingDuckAIController.h"


AFlyingDuckCharacter::AFlyingDuckCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AFlyingDuckAIController::StaticClass();
	mFlyingDuckHealth = 30.0f;
	mFlyingDuckDamage = 0.0f;
}

void AFlyingDuckCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFlyingDuckCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AFlyingDuckCharacter::SetupPlayerInputComponent(UInputComponent * InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

float AFlyingDuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.0f)
	{
		mFlyingDuckHealth -= ActualDamage;
		if (mFlyingDuckHealth <= 0.0f)
		{
			// We're dead, don't allow further damage
			bCanBeDamaged = false;
			// TODO: Process death
			float duration = PlayAnimMontage(FlyingDeathAnim);
			GetWorldTimerManager().SetTimer(mFlyingDeathTimer, this, &AFlyingDuckCharacter::DestroyDuck, duration - 0.25f, true);
			GetController()->UnPossess();
		}
	}
	return ActualDamage;
}

void AFlyingDuckCharacter::DestroyDuck()
{
	this->Destroy();
}
