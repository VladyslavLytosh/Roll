// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/RollPlayerComponent.h"

APlayerPawn::APlayerPawn()
{
	RollPlayerComponent = CreateDefaultSubobject<URollPlayerComponent>(TEXT("RollPlayerComponent"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent->bUsePawnControlRotation = false;
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	check(RollPlayerComponent);
	RollPlayerComponent->InitializePlayerInput(PlayerInputComponent);
}
