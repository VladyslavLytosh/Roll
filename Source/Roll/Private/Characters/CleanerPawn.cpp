// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CleanerPawn.h"

#include "Components/ShapeComponent.h"

ACleanerPawn::ACleanerPawn()
{
	ShapeComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHit);
}

void ACleanerPawn::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	ATargetPawnBase* PaintableActor = Cast<ATargetPawnBase>(OtherActor);
	if(!PaintableActor) return;
	
	if (bClean && !PaintableActor->bClean)
	{
		PaintableActor->Paint(PaintableActor->GetStartingPawnColor());
		PaintableActor->bClean = true;
		PaintableActor->NewColor = PaintableActor->GetStartingPawnColor();
	}
}

