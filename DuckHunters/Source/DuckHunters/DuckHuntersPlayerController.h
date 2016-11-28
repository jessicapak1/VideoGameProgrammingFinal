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
    
	UFUNCTION()
	void OnStartJump();

	UFUNCTION()
	void OnStopJump(); 
	void TurnAtRate(float Rate); 
	void LookUpRate(float Rate); 

	void OnStartFire();
	void OnStopFire(); 

	float BaseTurnRate; 
	float BaseLookUpRate;


    
protected:
    
    virtual void SetupInputComponent() override;
    
    virtual void PlayerTick(float DeltaTime) override;
	
};
