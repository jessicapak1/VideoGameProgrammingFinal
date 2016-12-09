// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckHuntersCharacter.h"
#include "DuckCharacter.h"
#include "DuckHuntersPlayerController.h"

#include "Weapon.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AWeapon::AWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;

	//set inital variables
	FireRate = .1f;
	WeaponRange = 10000.0f;
	MyOwner = nullptr;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AWeapon::WeaponTrace()
{
	static FName WeaponFireTag = FName(TEXT("WeaponTrace"));
	static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));

	// Start from the muzzle's position
	FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket);
	// Get forward vector of MyPawn
	FVector Forward = MyOwner->GetActorForwardVector();


	// Calculate end position
    FVector mousePos;
    FVector mouseDir;

	
    //auto PC = Cast<ADuckHuntersPlayerController>(MyOwner->GetController());
    //PC->DeprojectMousePositionToWorld(mousePos, mouseDir);
    mouseDir = MyOwner->GetFirstPersonCameraComponent()->GetForwardVector();
	FVector EndPos = StartPos + (mouseDir*WeaponRange);

	// Perform trace to retrieve hit info
	FCollisionQueryParams TraceParams(WeaponFireTag, true, Instigator);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;
	// This fires the ray and checks against all objects w/ collision
	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos, FCollisionObjectQueryParams::AllObjects, TraceParams);
	 DrawDebugLine(GetWorld(), StartPos, EndPos, FColor::Red, true);
	// Did this hit anything?
	if (Hit.bBlockingHit)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, HitEffect, Hit.ImpactPoint);
		ADuckCharacter* Duck = Cast<ADuckCharacter>(Hit.GetActor());


		if (Duck)
		{
			Duck->TakeDamage(rifleDamage, FDamageEvent(), GetInstigatorController(), this);
		}

	}
	
}

void AWeapon::OnStartFire()
{
	Muzzle = UGameplayStatics::SpawnEmitterAttached(MuzzleFx, WeaponMesh, TEXT("MuzzleFlashSocket"));
	FireAC = PlayWeaponSound(FireLoopSound); 
	GetWorldTimerManager().SetTimer(WeaponTimer, this, &AWeapon::WeaponTrace, FireRate, true);
}

void AWeapon::OnStopFire()
{
	if (FireAC > 0)
	{
		Muzzle->DeactivateSystem();
		FireAC->Stop();
		FireAC = PlayWeaponSound(FireFinishSound);
		GetWorldTimerManager().ClearTimer(WeaponTimer);
	}
}

void AWeapon::SetMyOwner( ADuckHuntersCharacter* owner)
{
	MyOwner = owner; 
}

ADuckHuntersCharacter* AWeapon::ReturnOwner()
{
	return MyOwner; 
}

USkeletalMeshComponent* AWeapon::GetWeaponMesh()
{
	return WeaponMesh; 
}

UAudioComponent * AWeapon::PlayWeaponSound(USoundCue* Sound)
{
	UAudioComponent* AC = NULL;
	if (Sound)
	{
		AC = UGameplayStatics::SpawnSoundAttached(Sound, RootComponent);
	}
	return AC;
}

