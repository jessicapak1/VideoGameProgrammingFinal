// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "DuckHuntersPlayerController.h"
#include "DuckHuntersCharacter.h"


ADuckHuntersPlayerController::ADuckHuntersPlayerController()
{

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
    
}
void ADuckHuntersPlayerController::MoveForward(float Value)
{
    if(Value != 0.0f)
    {
    APawn* playerController = GetPawn();
    
    if(playerController != nullptr)
    {
        playerController->AddMovementInput(FVector(1.0f,0.0f,0.0f),Value);
    }
    }
}

void ADuckHuntersPlayerController::MoveRight(float Value)
{
    
    if (Value !=0.0f)
    {
    
    }
}
