// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BasePawn.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
	DynamicMaterial = UMaterialInstanceDynamic::Create(PawnMaterial, nullptr);
	DynamicMaterial->SetVectorParameterValue("Color", StartingPawnColor);
	PawnMesh->SetMaterial(0,DynamicMaterial);
}

