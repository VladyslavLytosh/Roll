// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"

#include "RollGameMode.h"
#include "Camera/CameraComponent.h"
#include "Characters/TargetPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/RollPlayerComponent.h"

APlayerPawn::APlayerPawn()
{
	ShapeComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = ShapeComponent;
	
	RollPlayerComponent = CreateDefaultSubobject<URollPlayerComponent>(TEXT("RollPlayerComponent"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	
	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent->bUsePawnControlRotation = false;

	PawnMesh->SetupAttachment(RootComponent);
	
	ShapeComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHit);
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	check(RollPlayerComponent);
	RollPlayerComponent->InitializePlayerInput(PlayerInputComponent);
}

void APlayerPawn::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                 FVector NormalImpulse, const FHitResult& Hit)
{
	ATargetPawn* PaintableActor = Cast<ATargetPawn>(OtherActor);
	if(!PaintableActor) return;
	
	if (PaintableActor->IsClean())
	{
		PaintableActor->PaintTarget(StartingPawnColor);
		
		UGameplayStatics::PlaySoundAtLocation(this, PaintSound, PaintableActor->GetActorLocation(), PaintableActor->GetActorRotation());
		UGameplayStatics::SpawnEmitterAtLocation(this,PaintEmitter,PaintableActor->GetActorLocation(), PaintableActor->GetActorRotation());
	}
}
