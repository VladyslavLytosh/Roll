// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TargetPawnBase.h"
#include "CleanerPawn.generated.h"


UCLASS()
class ROLL_API ACleanerPawn : public ATargetPawnBase
{
	GENERATED_BODY()

public:
	ACleanerPawn();
	
private:
	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
