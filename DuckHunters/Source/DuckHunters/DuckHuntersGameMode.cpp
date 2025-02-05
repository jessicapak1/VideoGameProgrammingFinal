// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "DuckHunters.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
//#include "Blueprint/UserWidget.h"
#include "Engine.h"
#include "DuckHuntersGameMode.h"
#include "DuckHuntersHUD.h"
#include "DuckHuntersCharacter.h"
#include "DuckHuntersPlayerController.h"
ADuckHuntersGameMode::ADuckHuntersGameMode()
	: Super()
{
	PlayerControllerClass = ADuckHuntersPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("/Game/Blueprints/BP_DuckHuntersCharacter"));

	if (PlayerPawnObject.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnObject.Class; 
		//DefaultPawnClass = ADuckHuntersCharacter::StaticClass();
	}

	// use our custom HUD class
	HUDClass = ADuckHuntersHUD::StaticClass();
	
	mTimeRemaining = 60;
}

void ADuckHuntersGameMode::BeginPlay() {
	Super::BeginPlay();
	if (wHUD) {
		MyHUD = CreateWidget<UUserWidget>(GetWorld(), wHUD);
	}

	if (MyHUD) {
		MyHUD->AddToViewport();
	}

	mScore = 0;
	GetWorldTimerManager().SetTimer(mRoundTimer, this, &ADuckHuntersGameMode::DecrementTime, 1.0f, true);
}

void ADuckHuntersGameMode::IncrementScore() {
	mScore++;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(mScore));
}

void ADuckHuntersGameMode::DecrementTime() {
	mTimeRemaining--;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(mTimeRemaining));
}

void ADuckHuntersGameMode::PauseGame() {
	mPaused = true;
	GetWorldTimerManager().PauseTimer(mRoundTimer);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Game is paused")));
}

void ADuckHuntersGameMode::UnpauseGame() {
	mPaused = false;
	GetWorldTimerManager().UnPauseTimer(mRoundTimer);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Game is paused")));
}
