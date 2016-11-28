// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
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

protected:

	UPROPERTY(EditAnyWhere, Category = Damage)
	float hunterHealth = 100.0f;
	
	UPROPERTY(EditAnyWhere, Category = Weapon)
	TSubclassOf<class AWeapon> WeaponClass; 

	
	
};

