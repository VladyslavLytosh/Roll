// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RollHUD.h"

#include "Blueprint/UserWidget.h"

void ARollHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetOwningPlayerController();
	
	GameHUDWidget = CreateWidget(PlayerController, GameHUDClass);
	GameHUDWidget->AddToViewport();

	/*VictoryScreenWidget = CreateWidget(PlayerController, VictoryScreenClass);
	VictoryScreenWidget->AddToViewport();*/
}
