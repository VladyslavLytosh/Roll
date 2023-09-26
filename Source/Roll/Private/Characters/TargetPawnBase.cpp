// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TargetPawnBase.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

ATargetPawnBase::ATargetPawnBase()
{
	ShapeComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = ShapeComponent;
	PawnMesh->SetupAttachment(RootComponent);
	
	ShapeComponent->SetSimulatePhysics(true);
	ShapeComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ShapeComponent->SetCollisionResponseToAllChannels(ECR_Block);
}

void ATargetPawnBase::Paint(const FColor& Color)
{
	DynamicMaterial->SetVectorParameterValue("Color", Color);
}

void ATargetPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindLambda([&]()
	{
		ShapeComponent->AddImpulse(UKismetMathLibrary::RandomUnitVector().GetSafeNormal2D() * Speed, NAME_None, true);
	});
	GetWorldTimerManager().SetTimer(ForceTimer, TimerDelegate, MoveRate,true);
}


