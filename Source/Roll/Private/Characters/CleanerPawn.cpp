// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CleanerPawn.h"

#include "RollGameMode.h"
#include "Kismet/GameplayStatics.h"


void ACleanerPawn::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	ATargetPawn* PaintableActor = Cast<ATargetPawn>(OtherActor);
	if(!PaintableActor) return;
	
	if (IsClean() && !PaintableActor->IsClean())
	{
		PaintableActor->CleanTarget();
		return;
	}

	Super::OnComponentHit(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}

