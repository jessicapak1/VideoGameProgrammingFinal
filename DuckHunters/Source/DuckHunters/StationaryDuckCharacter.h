// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DuckCharacter.h"
#include "StationaryDuckCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API AStationaryDuckCharacter : public ADuckCharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AStationaryDuckCharacter();

	// Called when the game starts or when spawned
	void BeginPlay() override;

	// Called every frame
	void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void DestroyDuck();

private:
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* StationaryAttackAnim;
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* StationaryDeathAnim;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mStationaryDuckHealth;
	UPROPERTY(EditAnywhere, Category = Damage)
		float mStationaryDuckDamage;
	FTimerHandle mStationaryDeathTimer;
	FTimerHandle mStationaryAttackTimer;
	
	
};
