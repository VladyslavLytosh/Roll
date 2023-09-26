// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TargetPawn.h"
#include "Characters/TargetPawnBase.h"
#include "CleanerPawn.generated.h"


UCLASS()
class ROLL_API ACleanerPawn : public ATargetPawn
{
	GENERATED_BODY()

protected:
	virtual void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
