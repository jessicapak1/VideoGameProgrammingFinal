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
	void BeginPlay() override;

	// Called every frame
	void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void StartAttack();
	void StopAttack();
	void DestroyDuck();
	void AttackPlayer();
	
private:
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* AttackingAttackAnim;
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* AttackingDeathAnim;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mAttackingDuckHealth;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mAttackingDuckDamage;
	FTimerHandle mAttackingDeathTimer;
	FTimerHandle mAttackingAttackTimer;
};
