// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "DuckHunters.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "DuckHuntersHUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"

ADuckHuntersHUD::ADuckHuntersHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FClassFinder<UUserWidget> hudWidgetObj(TEXT("/Game/HUD/HUD"));
	if (hudWidgetObj.Succeeded()) {
		hudWidgetClass = hudWidgetObj.Class;
	}
	else {
		hudWidgetClass = nullptr;
	}
}

void ADuckHuntersHUD::BeginPlay() {
	Super::BeginPlay();
	if (hudWidgetClass) {
		hudWidget = CreateWidget<UUserWidget>(this->GetOwningPlayerController(), this->hudWidgetClass);
		hudWidget->AddToViewport();
	}
}


void ADuckHuntersHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y));

	// draw the crosshair
	/*FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
     */
}

