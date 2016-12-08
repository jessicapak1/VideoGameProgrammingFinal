// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

//#include "Animation/AnimInstance.h"
//#include "GameFramework/InputSettings.h"
//#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
//#include "MotionControllerComponent.h"

#include "DuckHunters.h"
#include "DuckCharacter.h"
#include "DuckHuntersCharacter.h"
#include "DuckHuntersPlayerController.h"
#include "Weapon.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ADuckHuntersCharacter

ADuckHuntersCharacter::ADuckHuntersCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);



	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;


	// Uncomment the following line to turn motion controllers on by default:
	//bUsingMotionControllers = true;
	MaxhunterHealth = 100.0f;
	hunterHealth = MaxhunterHealth;

	MyWeapon = nullptr; 
}

void ADuckHuntersCharacter::BeginPlay()
{		// Call base class BeginPlay
		Super::BeginPlay();
    
    //GetMesh()->AttachToComponent(FirstPersonCameraComponent, FAttachment  )
		// Spawn the weapon, if one was specified
		if (WeaponClass)
		{
			UWorld* World = GetWorld();
			if (World)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				SpawnParams.Instigator = Instigator;
				// Need to set rotation like this because otherwise gun points down
				FRotator Rotation(0.0f, 0.0f, -90.0f);
				// Spawn the Weapon
				MyWeapon = World->SpawnActor<AWeapon>(WeaponClass, FVector::ZeroVector,
					Rotation, SpawnParams);
				if (MyWeapon)
				{
					// This is attached to "WeaponPoint" which is defined in the skeleton
					MyWeapon->AttachToComponent(GetMesh(),
						FAttachmentTransformRules::KeepRelativeTransform,
						TEXT("WeaponPoint"));

					MyWeapon->SetMyOwner(this); 
				}
			}
		}

		if (GetWorld()) 
		{
			mGameMode = (ADuckHuntersGameMode*)GetWorld()->GetAuthGameMode();
		}
	
}


void ADuckHuntersCharacter::OnStartFire()
{
	if (MyWeapon != nullptr)
	{
		MyWeapon->OnStartFire(); 
	}
}

void ADuckHuntersCharacter::OnStopFire()
{
	if (MyWeapon != nullptr)
	{
		MyWeapon->OnStopFire(); 
	}
}
bool ADuckHuntersCharacter::IsDead()
{
	if (hunterHealth <= 0)
	{
		return true; 
	}

	else
	{
		return false; 
	}
}

float ADuckHuntersCharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,  "Player Take Damage");
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.0f)
	{
		hunterHealth -= ActualDamage;
		int i = 2;
		if (hunterHealth <= 0.0f)
		{
			// We're dead, don't allow further damage
			mDead = true;
			bCanBeDamaged = false;
			// TODO: Process death
			float duration = 1.0f;
				//PlayAnimMontage(DeathAnim);
			ADuckHuntersPlayerController* PC = Cast<ADuckHuntersPlayerController>(GetController());
			if (PC)
			{
				PC->SetCinematicMode(true, true, true);
			}
			GetWorldTimerManager().SetTimer(mDeathTimer, this, &ADuckHuntersCharacter::DestroyPlayer, duration - 0.25f, true);
			OnStopFire();
		}
	}
	return ActualDamage;
}

void ADuckHuntersCharacter::DestroyPlayer()
{
	mGameMode->PauseGame();
}