// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BasePawn.h"

#include "Components/CapsuleComponent.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	PawnMesh->SetupAttachment(RootComponent);
	
}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
	DynamicMaterial = UMaterialInstanceDynamic::Create(PawnMaterial, nullptr);
	DynamicMaterial->SetVectorParameterValue("Color", PawnColor);
	PawnMesh->SetMaterial(0,DynamicMaterial);
}

