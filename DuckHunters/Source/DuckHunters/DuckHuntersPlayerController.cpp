// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckHuntersPlayerController.h"
#include "DuckHuntersCharacter.h"


ADuckHuntersPlayerController::ADuckHuntersPlayerController()
{
	//bShowMouseCursor = true; 
	//DefaultMouseCursor = EMouseCursor::Crosshairs; 

	BaseLookUpRate = 45.f;
	BaseTurnRate = 45.f;
}


void ADuckHuntersPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
    
}


void ADuckHuntersPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
  

    InputComponent->BindAxis("MoveForward", this, &ADuckHuntersPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &ADuckHuntersPlayerController::MoveRight);
	
	

	
	InputComponent->BindAxis("Turn", this, &ADuckHuntersPlayerController::AddYawInput);
	InputComponent->BindAxis("LookUp", this, &ADuckHuntersPlayerController::AddPitchInput);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ADuckHuntersPlayerController::OnStartJump); 
	InputComponent->BindAction("Jump", IE_Released, this, &ADuckHuntersPlayerController::OnStopJump);

	InputComponent->BindAction("Fire", IE_Pressed, this, &ADuckHuntersPlayerController::OnStartFire); 
	InputComponent->BindAction("Fire", IE_Released, this, &ADuckHuntersPlayerController::OnStopFire);



}
void ADuckHuntersPlayerController::MoveForward(float Value)
{
	APawn* playerHunter = GetPawn();

	if(Value != 0.0f && playerHunter != nullptr)
    {
      
        playerHunter->AddMovementInput(playerHunter->GetActorForwardVector(),Value);
    }
    
}

void ADuckHuntersPlayerController::MoveRight(float Value)
{
    
	APawn* playerHunter = GetPawn(); 

	if (Value != 0.0f && playerHunter != nullptr)
	{

		// add movement in that direction
		playerHunter->AddMovementInput(GetActorRightVector(), Value);
	}
}

void ADuckHuntersPlayerController::OnStartJump()
{ 
	ADuckHuntersCharacter* playerHunter = Cast<ADuckHuntersCharacter>(GetPawn());
	playerHunter->bPressedJump = true; 
}

void ADuckHuntersPlayerController::OnStopJump()
{
	ADuckHuntersCharacter* playerHunter = Cast<ADuckHuntersCharacter>(GetPawn()); 
	playerHunter->bPressedJump = false; 
}

void ADuckHuntersPlayerController::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	APawn *player = GetPawn(); 
	player->AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}


void ADuckHuntersPlayerController::LookUpRate(float Rate)
{
	APawn *player = GetPawn(); 
	player->AddControllerPitchInput(Rate* BaseLookUpRate * GetWorld()->GetDeltaSeconds()); 
}

void ADuckHuntersPlayerController::OnStartFire()
{
	ADuckHuntersCharacter *hunter = Cast<ADuckHuntersCharacter>(GetPawn()); 
	if (hunter->IsDead() == false)
	{
		hunter->OnStartFire(); 
	}
}

void ADuckHuntersPlayerController::OnStopFire()
{
	ADuckHuntersCharacter *hunter = Cast<ADuckHuntersCharacter>(GetPawn()); 
	if (hunter->IsDead() == false)
	{
		hunter->OnStopFire(); 
	}
}
