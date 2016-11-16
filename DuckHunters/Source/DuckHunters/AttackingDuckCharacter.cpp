// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckHuntersCharacter.h"
#include "AttackingDuckCharacter.h"
#include "AttackingDuckAIController.h"
#include <iostream>

AAttackingDuckCharacter::AAttackingDuckCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AAttackingDuckAIController::StaticClass();
	mDuckHealth = 40.0f;
	mDuckDamage = 10.0f;
	std::cout << "inside attack constructor " << std::endl;
}

float AAttackingDuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
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
			StopAttack();
            DestroyDuck();
			float duration = PlayAnimMontage(DeathAnim);
			GetWorldTimerManager().SetTimer(mDeathTimer, this, &ADuckCharacter::DestroyDuck, duration - 0.25f, true);
			GetController()->UnPossess();
		}
	}
	return ActualDamage;
}

void AAttackingDuckCharacter::StartAttack()
{
	float duration = PlayAnimMontage(AttackAnim);
	GetWorldTimerManager().SetTimer(mAttackTimer, this, &AAttackingDuckCharacter::AttackPlayer, duration, true);
}

void AAttackingDuckCharacter::StopAttack()
{
	StopAnimMontage(AttackAnim);
	GetWorldTimerManager().ClearTimer(mAttackTimer);
}


void AAttackingDuckCharacter::AttackPlayer()
{
	ADuckHuntersCharacter* player = Cast<ADuckHuntersCharacter>(UGameplayStatics::GetPlayerPawn(this, 0)); // player
	if (player != nullptr)
	{
		player->TakeDamage(mDuckDamage, FDamageEvent(), GetInstigatorController(), this);
	}
}

void AAttackingDuckCharacter::DestroyDuck()
{
    this->Destroy();
}
