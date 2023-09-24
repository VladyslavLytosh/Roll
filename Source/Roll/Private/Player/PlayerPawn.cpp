// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"

#include "Player/RollPlayerComponent.h"

APlayerPawn::APlayerPawn()
{
	RollPlayerComponent = CreateDefaultSubobject<URollPlayerComponent>(TEXT("RollPlayerComponent"));
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	check(RollPlayerComponent);
	RollPlayerComponent->InitializePlayerInput(PlayerInputComponent);
}
