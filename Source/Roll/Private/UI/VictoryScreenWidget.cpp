// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/VictoryScreenWidget.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UVictoryScreenWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	RestartButton->OnClicked.AddDynamic(this, &ThisClass::OnRestartClicked);
}

void UVictoryScreenWidget::OnRestartClicked()
{
	UGameplayStatics::OpenLevel(this,FName(*UGameplayStatics::GetCurrentLevelName(this)));
}
