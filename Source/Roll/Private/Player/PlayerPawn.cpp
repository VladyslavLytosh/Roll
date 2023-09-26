// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"

#include "RollGameMode.h"
#include "Camera/CameraComponent.h"
#include "Characters/TargetPawnBase.h"
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

	ShapeComponent->SetSimulatePhysics(true);
	ShapeComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ShapeComponent->SetCollisionResponseToAllChannels(ECR_Block);
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
	ATargetPawnBase* PaintableActor = Cast<ATargetPawnBase>(OtherActor);
	if(!PaintableActor) return;
	
	if (PaintableActor->bClean)
	{
		PaintableActor->Paint(StartingPawnColor);
		PaintableActor->bClean = false;
		PaintableActor->NewColor = StartingPawnColor;
		
		ARollGameMode* RollGameMode = Cast<ARollGameMode>(UGameplayStatics::GetGameMode(this));
		
		RollGameMode->OnPaintTarget(PaintableActor);

		UGameplayStatics::PlaySoundAtLocation(this, PaintSound, PaintableActor->GetActorLocation(), PaintableActor->GetActorRotation());
		UGameplayStatics::SpawnEmitterAtLocation(this,PaintEmitter,PaintableActor->GetActorLocation(), PaintableActor->GetActorRotation());
	}
}
