// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "Engine.h"
#include "DuckCharacter.h"
#include <iostream>

// Sets default values
ADuckCharacter::ADuckCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mDuckHealth = 20.0f;
	mDuckDamage = 0.0f;
	std::cout << "inside duck constructor " << std::endl;
}

// Called when the game starts or when spawned
void ADuckCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	/*TArray<UStaticMeshComponent*> Components;
	this->GetComponents<UStaticMeshComponent>(Components);
	mStaticMeshComponent = Components[0];
	mStaticMesh = mStaticMeshComponent->StaticMesh;
	mStaticMeshComponent->bGenerateOverlapEvents = true;
	mStaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ADuckCharacter::OnBeginOverlap);*/
}

/*void ADuckCharacter::OnBeginOverlap(class UPrimitiveComponent* thisComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "HIT");
	OtherActor->TakeDamage(5, FDamageEvent(), GetInstigatorController(), this);
		
}*/

// Called every frame
void ADuckCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ADuckCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
/*
float ADuckCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
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
}*/

void ADuckCharacter::DestroyDuck()
{
	this->Destroy();
}
