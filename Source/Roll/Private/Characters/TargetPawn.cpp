// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TargetPawn.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

ATargetPawn::ATargetPawn()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;
	PawnMesh->SetupAttachment(RootComponent);
}

void ATargetPawn::Paint(const FColor& Color)
{
	DynamicMaterial->SetVectorParameterValue("Color", Color);
}

void ATargetPawn::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindLambda([&]()
	{
		BoxComponent->AddImpulse(UKismetMathLibrary::RandomUnitVector().GetSafeNormal2D() * 500, NAME_None, true);
	});
	GetWorldTimerManager().SetTimer(ForceTimer, TimerDelegate, 1.f,true);
}
