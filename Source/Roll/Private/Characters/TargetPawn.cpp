// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TargetPawn.h"

#include "RollGameMode.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

ATargetPawn::ATargetPawn()
{
	ShapeComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = ShapeComponent;
	PawnMesh->SetupAttachment(RootComponent);
	
	Cast<UBoxComponent>(ShapeComponent)->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHit);
}

void ATargetPawn::ChangeColor(const FColor& InColor)
{
	DynamicMaterial->SetVectorParameterValue("Color", InColor);
}

void ATargetPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	GetWorldTimerManager().ClearTimer(ForceTimer);
	
	GetWorldTimerManager().SetTimer(ForceTimer, this, &ThisClass::MovePawn, MoveRate,true);
}

void ATargetPawn::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{	
	ATargetPawn* PaintableActor = Cast<ATargetPawn>(OtherActor);
	if(!PaintableActor) return;
	
	if (!bIsClean && PaintableActor->bIsClean)
	{
		PaintableActor->PaintTarget(NewColor);
	}
}

void ATargetPawn::MovePawn()
{
	ShapeComponent->AddImpulse(UKismetMathLibrary::RandomUnitVector().GetSafeNormal2D() * Speed, NAME_None, true);
}

void ATargetPawn::PaintTarget(const FColor& InColor)
{
	this->ChangeColor(InColor);
	this->bIsClean = false;
	this->NewColor = InColor;
		
	ARollGameMode* RollGameMode = Cast<ARollGameMode>(UGameplayStatics::GetGameMode(this));
	RollGameMode->OnPaintTarget(this);
}

void ATargetPawn::CleanTarget()
{
	this->ChangeColor(this->GetStartingPawnColor());
	this->bIsClean = true;
	this->NewColor = this->GetStartingPawnColor();
		
	ARollGameMode* RollGameMode = Cast<ARollGameMode>(UGameplayStatics::GetGameMode(this));
		
	RollGameMode->OnCleanTarget(this);
}



