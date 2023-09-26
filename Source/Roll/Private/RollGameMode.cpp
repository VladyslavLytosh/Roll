// Fill out your copyright notice in the Description page of Project Settings.


#include "RollGameMode.h"

#include "Characters/CleanerPawn.h"
#include "Kismet/GameplayStatics.h"

int32 ARollGameMode::GetNumCleanerTargets()
{
	TArray<AActor*> Cleaners;
	UGameplayStatics::GetAllActorsOfClass(this,ACleanerPawn::StaticClass(),Cleaners);
	int32 Count=0;
	for (const auto& Cleaner : Cleaners)
	{
		if (Cast<ACleanerPawn>(Cleaner)->bClean)
		{
			Count++;
		}
	}
	return Count;
}
