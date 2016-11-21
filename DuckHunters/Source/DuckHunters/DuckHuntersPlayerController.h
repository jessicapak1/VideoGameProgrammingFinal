// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "DuckHuntersPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTERS_API ADuckHuntersPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
	
public:
    
    ADuckHuntersPlayerController();
    
    void MoveForward(float Value);
    void MoveRight(float Value); 
    
    
protected:
    
    virtual void SetupInputComponent() override;
    
    virtual void PlayerTick(float DeltaTime) override;
	
};
