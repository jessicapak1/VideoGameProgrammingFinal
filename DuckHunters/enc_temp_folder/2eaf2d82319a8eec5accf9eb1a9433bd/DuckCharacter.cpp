// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckCharacter.h"


// Sets default values
ADuckCharacter::ADuckCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADuckCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADuckCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ADuckCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

