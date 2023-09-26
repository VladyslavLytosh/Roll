// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CleanersCounterWidget.h"

#include "RollGameMode.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UCleanersCounterWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	ARollGameMode* RollGameMode = Cast<ARollGameMode>(UGameplayStatics::GetGameMode(this));
	CleanersNum->SetText(FText::AsNumber(RollGameMode->GetNumCleanerTargets()));
}
