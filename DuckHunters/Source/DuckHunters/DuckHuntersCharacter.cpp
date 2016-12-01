// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

//#include "Animation/AnimInstance.h"
//#include "GameFramework/InputSettings.h"
//#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
//#include "MotionControllerComponent.h"

#include "DuckHunters.h"
#include "DuckCharacter.h"
#include "DuckHuntersCharacter.h"
#include "Weapon.h"

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

	hunterHealth = MaxhunterHealth;

	MyWeapon = nullptr; 
}

void ADuckHuntersCharacter::BeginPlay()
{		// Call base class BeginPlay
		Super::BeginPlay();
    
    GetMesh()->AttachToComponent(FirstPersonCameraComponent, FAttachment  )
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

