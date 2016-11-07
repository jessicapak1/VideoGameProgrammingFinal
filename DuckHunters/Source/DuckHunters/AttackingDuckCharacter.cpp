// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckHuntersCharacter.h"
#include "AttackingDuckCharacter.h"
#include "AttackingDuckAIController.h"

AAttackingDuckCharacter::AAttackingDuckCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AAttackingDuckAIController::StaticClass();
	mAttackingDuckHealth = 40.0f;
	mAttackingDuckDamage = 10.0f;
}

void AAttackingDuckCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAttackingDuckCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AAttackingDuckCharacter::SetupPlayerInputComponent(UInputComponent * InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

float AAttackingDuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.0f)
	{
		mAttackingDuckHealth -= ActualDamage;
		if (mAttackingDuckHealth <= 0.0f)
		{
			// We're dead, don't allow further damage
			bCanBeDamaged = false;
			// TODO: Process death
			StopAttack();
			float duration = PlayAnimMontage(AttackingDeathAnim);
			GetWorldTimerManager().SetTimer(mAttackingDeathTimer, this, &AAttackingDuckCharacter::DestroyDuck, duration - 0.25f, true);
			GetController()->UnPossess();
		}
	}
	return ActualDamage;
}

void AAttackingDuckCharacter::StartAttack()
{
	float duration = PlayAnimMontage(AttackingAttackAnim);
	GetWorldTimerManager().SetTimer(mAttackingAttackTimer, this, &AAttackingDuckCharacter::AttackPlayer, duration, true);
}

void AAttackingDuckCharacter::StopAttack()
{
	StopAnimMontage(AttackingAttackAnim);
	GetWorldTimerManager().ClearTimer(mAttackingAttackTimer);
}

void AAttackingDuckCharacter::DestroyDuck()
{
	this->Destroy();
}

void AAttackingDuckCharacter::AttackPlayer()
{
	ADuckHuntersCharacter* player = Cast<ADuckHuntersCharacter>(UGameplayStatics::GetPlayerPawn(this, 0)); // player
	if (player != nullptr)
	{
		player->TakeDamage(mAttackingDuckDamage, FDamageEvent(), GetInstigatorController(), this);
	}
}
