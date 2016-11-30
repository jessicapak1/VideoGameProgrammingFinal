// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "DuckCharacter.generated.h"

UCLASS()
class DUCKHUNTERS_API ADuckCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADuckCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void DestroyDuck();
protected:
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* AttackAnim;
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* DeathAnim;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mDuckHealth;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mDuckDamage;
	FTimerHandle mDeathTimer;


};
