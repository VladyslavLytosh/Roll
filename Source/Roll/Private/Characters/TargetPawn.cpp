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
	
	ShapeComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHit);
}

void ATargetPawn::Paint(const FColor& Color)
{
	DynamicMaterial->SetVectorParameterValue("Color", Color);
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
	
	if (!bClean && PaintableActor->bClean)
	{
		PaintableActor->Paint(NewColor);
		PaintableActor->bClean = false;
		PaintableActor->NewColor = this->NewColor;
		
		ARollGameMode* RollGameMode = Cast<ARollGameMode>(UGameplayStatics::GetGameMode(this));
		
		RollGameMode->OnPaintTarget(PaintableActor);
	}
}

void ATargetPawn::MovePawn()
{
	ShapeComponent->AddImpulse(UKismetMathLibrary::RandomUnitVector().GetSafeNormal2D() * Speed, NAME_None, true);
}



