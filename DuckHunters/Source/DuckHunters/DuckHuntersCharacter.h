// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "DuckHuntersGameMode.h"
#include "GameFramework/Character.h"
#include "DuckHuntersCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class ADuckHuntersCharacter : public ACharacter
{
	GENERATED_BODY()

	FTimerHandle WeaponTimer;

	class AWeapon* MyWeapon;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;


public:
	ADuckHuntersCharacter();
	
	virtual void BeginPlay();



	void OnStartFire();
	void OnStopFire(); 

	bool IsDead(); 


	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	uint32 bUsingMotionControllers : 1;

	float getHealth() { return hunterHealth; }
	float ADuckHuntersCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser);
	void ADuckHuntersCharacter::DestroyPlayer();
protected:

	UPROPERTY(EditAnyWhere, Category = Damage)
		float hunterHealth;
	UPROPERTY(EditAnyWhere, Category = Damage)
		float MaxhunterHealth = 100.0f;
	
	UPROPERTY(EditDefaultsOnly)
	class UAnimMontage* DeathAnim;
	
	FTimerHandle mDeathTimer2;
	UPROPERTY(EditAnyWhere, Category = Weapon)
	TSubclassOf<class AWeapon> WeaponClass;
    
    UPROPERTY(EditAnyWhere, Category = Mesh)
    USkeletalMeshComponent *hunterMesh;

	bool mDead;
	ADuckHuntersGameMode* mGameMode;
	
	
};

