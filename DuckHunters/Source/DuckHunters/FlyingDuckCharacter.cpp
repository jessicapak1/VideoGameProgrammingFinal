// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckHuntersCharacter.h"
#include "FlyingDuckCharacter.h"
#include "Engine.h"
#include "FlyingDuckAIController.h"


AFlyingDuckCharacter::AFlyingDuckCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AFlyingDuckAIController::StaticClass();
	mDuckHealth = 30.0f;
	mDuckDamage = 0.0f;
}

void AFlyingDuckCharacter::BeginPlay()
{
	TArray<UStaticMeshComponent*> components;
	this->GetComponents<UStaticMeshComponent>(components);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Number of components");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(components.Num()));
}

float AFlyingDuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
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
            DestroyDuck();
			float duration = PlayAnimMontage(DeathAnim);
			GetWorldTimerManager().SetTimer(mDeathTimer, this, &ADuckCharacter::DestroyDuck, duration - 0.25f, true);
			//GetController()->UnPossess();
		}
	}
	return ActualDamage;
}

void AFlyingDuckCharacter::DestroyDuck()
{
	ADuckHuntersCharacter* player = Cast<ADuckHuntersCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	player->incrementScore(15);
    this->Destroy();
}
