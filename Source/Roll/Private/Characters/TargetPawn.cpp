// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TargetPawn.h"

#include "RollGameMode.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"


ATargetPawn::ATargetPawn()
{
	ShapeComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHit);
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

