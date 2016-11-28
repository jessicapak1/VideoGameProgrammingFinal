// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class DUCKHUNTERS_API AWeapon : public AActor
{
	GENERATED_BODY()

	class ADuckHuntersCharacter* MyOwner; 
	FTimerHandle WeaponTimer; 

public:	
	// Sets default values for this actor's properties
	AWeapon();

	// Functions to Override
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

	//Functions to return components
	USkeletalMeshComponent* GetWeaponMesh(); 
	UAudioComponent* PlayWeaponSound(class USoundCue* Sound); 


	//Functions to Fire
	void OnStartFire(); 
	void OnStopFire(); 

	//Functions Setting & Returning Owner
	class ADuckHuntersCharacter* ReturnOwner(); 
	void SetMyOwner(class ADuckHuntersCharacter* owner); 

	void WeaponTrace(); 


protected:

	//Property for the weapons mesh
	UPROPERTY(VisibleDefaultsOnly, BluePrintReadOnly, Category = Weapon)
	USkeletalMeshComponent* WeaponMesh; 
	

	//Properties controlling the sound effects for firing
	UPROPERTY(EditDefaultsOnly, Category = Sound)
	class USoundCue* FireLoopSound;
	UPROPERTY(EditDefaultsOnly, Category = Sound)
	class USoundCue* FireFinishSound;
	UPROPERTY(Transient)
	class UAudioComponent* FireAC;


	//Property for the firing effects
	UPROPERTY(EditDefaultsOnly, Category = Effects)
	UParticleSystem* MuzzleFx; 
	UPROPERTY(Transient)
	class UParticleSystemComponent* Muzzle; 
	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* HitEffect;


	//Properties controlling firing range and rate
	UPROPERTY(EditAnyWhere)
		float FireRate;
	UPROPERTY(EditAnyWhere)
		float WeaponRange; 

	//Property controlling the amount of damage 	
	UPROPERTY(EditAnyWhere, Category = Damage)
		float rifleDamage = 2.0f;

};
