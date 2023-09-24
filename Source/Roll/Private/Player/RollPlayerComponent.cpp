// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RollPlayerComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void URollPlayerComponent::InitializePlayerInput(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	const APawn* Pawn = GetPawn<APawn>();
	if (!Pawn)	return;

	const APlayerController* PC = GetController<APlayerController>();
	check(PC);
	
	const ULocalPlayer* LP = Cast<ULocalPlayer>(PC->GetLocalPlayer());
	check(LP);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	
	Subsystem->ClearAllMappings();
	
	Subsystem->AddMappingContext(DefaultMappingContext,0);
	
	UEnhancedInputComponent* InputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	InputComponent->BindAction(MoveAction,ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	
	InputComponent->BindAction(LookAction,ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

}

void URollPlayerComponent::Input_Move(const FInputActionValue& InputActionValue)
{
	
}

void URollPlayerComponent::Input_Look(const FInputActionValue& InputActionValue)
{
	
}
