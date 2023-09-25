// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RollPlayerComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Player/PlayerPawn.h"

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
	APlayerPawn* Pawn = GetPawn<APlayerPawn>();
	const auto Controller = Pawn ? Pawn->GetController() : nullptr;

	if (!Controller) return;

	const FVector2D Value = InputActionValue.Get<FVector2D>();
	
	const FRotator Rotation = Pawn->Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (Value.X != 0.0f)
	{
		Pawn->GetCapsuleComponent()->AddForce(RightDirection * MovementSpeed * Value.X, NAME_None,true);
	}

	if (Value.Y != 0.0f)
	{
		Pawn->GetCapsuleComponent()->AddForce(ForwardDirection * MovementSpeed * Value.Y, NAME_None,true);
	}
}

void URollPlayerComponent::Input_Look(const FInputActionValue& InputActionValue)
{
	APawn* Pawn = GetPawn<APawn>();

	if (!Pawn) return;
	
	const FVector2D Value = InputActionValue.Get<FVector2D>();

	if (Value.X != 0.0f)
	{
		Pawn->AddControllerYawInput(Value.X);
	}

	if (Value.Y != 0.0f)
	{
		Pawn->AddControllerPitchInput(Value.Y);
	}
}
