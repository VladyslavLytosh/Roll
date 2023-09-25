// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Gameplay/Paintable.h"
#include "Player/RollPlayerComponent.h"

APlayerPawn::APlayerPawn()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;
	
	RollPlayerComponent = CreateDefaultSubobject<URollPlayerComponent>(TEXT("RollPlayerComponent"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent->bUsePawnControlRotation = false;

	PawnMesh->SetupAttachment(RootComponent);
	
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	check(RollPlayerComponent);
	RollPlayerComponent->InitializePlayerInput(PlayerInputComponent);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	CapsuleComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHit);
}

void APlayerPawn::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                 FVector NormalImpulse, const FHitResult& Hit)
{
	IPaintable* PaintableActor = Cast<IPaintable>(OtherActor);
	
	if(!PaintableActor) return;

	PaintableActor->Paint(PawnColor);
}
