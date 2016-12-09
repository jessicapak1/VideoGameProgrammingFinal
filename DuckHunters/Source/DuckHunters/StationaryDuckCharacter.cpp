// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckHuntersCharacter.h"
#include "Engine.h"
#include "StationaryDuckCharacter.h"



void AStationaryDuckCharacter::BeginPlay() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Spawned stationary duck");
	

	/*TArray<UStaticMeshComponent*> components;
	this->GetComponents<UStaticMeshComponent>(components);
	UStaticMeshComponent* smc = components[0];
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, smc->GetName());
	*/
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
			
			DestroyDuck();
			float duration = PlayAnimMontage(DeathAnim);
			GetWorldTimerManager().SetTimer(mDeathTimer, this, &ADuckCharacter::DestroyDuck, duration - 0.25f, true);
			//GetController()->UnPossess();
		}
	}
	return ActualDamage;
}

void AStationaryDuckCharacter::DestroyDuck()
{
	ADuckHuntersCharacter* player = Cast<ADuckHuntersCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	player->incrementScore(5);
	this->Destroy();
}