// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunters.h"
#include "Engine.h"
#include "StationaryDuckCharacter.h"



void AStationaryDuckCharacter::BeginPlay() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Spawned stationary duck");
	

	/*TArray<UStaticMeshComponent*> components;
	this->GetComponents<UStaticMeshComponent>(components);
	UStaticMeshComponent* smc = components[0];
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, smc->GetName());
	*/
}
