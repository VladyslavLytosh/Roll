// Fill out your copyright notice in the Description page of Project Settings.


#include "RollGameMode.h"

#include "Characters/CleanerPawn.h"
#include "Kismet/GameplayStatics.h"
#include "UI/RollHUD.h"


void ARollGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	TargetsCount = GetNumAlLTargets();
	CleanersCount = GetNumCleanerTargets();
}


int32 ARollGameMode::GetNumCleanerTargets() const
{
	TArray<AActor*> Cleaners;
	UGameplayStatics::GetAllActorsOfClass(this,ACleanerPawn::StaticClass(),Cleaners);
	int32 Count=0;
	for (const auto& Cleaner : Cleaners)
	{
		if (Cast<ACleanerPawn>(Cleaner)->IsClean())
		{
			Count++;
		}
	}
	return Count;
}

int32 ARollGameMode::GetNumAlLTargets() const
{
	TArray<AActor*> Targets;
	UGameplayStatics::GetAllActorsOfClass(this,ATargetPawn::StaticClass(),Targets);
	int32 Count=0;
	for (const auto& Target : Targets)
	{
		if (Cast<ATargetPawn>(Target)->IsClean())
		{
			Count++;
		}
	}
	return Count;
}

void ARollGameMode::CheckWinCondition()
{
	if (TargetsCount == 0)
	{
		const ARollHUD* RollHUD = Cast<ARollHUD>(UGameplayStatics::GetPlayerController(this,0)->GetHUD());
		check(RollHUD);
		
		RollHUD->ToggleVictoryScreenWidget();
	}
}

void ARollGameMode::OnPaintTarget(ATargetPawn* Target)
{
	TargetsCount--;
	if (Cast<ACleanerPawn>(Target))
	{
		CleanersCount--;
	}
	CheckWinCondition();
}

void ARollGameMode::OnCleanTarget(ATargetPawn* Target)
{
	TargetsCount++;
	if (Cast<ACleanerPawn>(Target))
	{
		CleanersCount++;
	}
}

