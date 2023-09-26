// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RollHUD.h"

#include "Blueprint/UserWidget.h"

void ARollHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetOwningPlayerController();

	checkf(GameHUDClass && VictoryScreenClass, TEXT("Widgets classes aren't setted"))
	
	GameHUDWidget = CreateWidget(PlayerController, GameHUDClass);
	GameHUDWidget->AddToViewport();

	VictoryScreenWidget = CreateWidget(PlayerController, VictoryScreenClass);
	VictoryScreenWidget->AddToViewport();
}

void ARollHUD::ToggleVictoryScreenWidget() const
{
	if (VictoryScreenWidget->GetVisibility() == ESlateVisibility::Collapsed)
	{
		VictoryScreenWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	else
	{
		VictoryScreenWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}