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
	void BeginPlay() override;

	// Called every frame
	void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void DestroyDuck();

private:
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* FlyingAttackAnim;
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* FlyingDeathAnim;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mFlyingDuckHealth;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mFlyingDuckDamage;
	FTimerHandle mFlyingDeathTimer;
	FTimerHandle mFlyingAttackTimer;
	
	
	
};
