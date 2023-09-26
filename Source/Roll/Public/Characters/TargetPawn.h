// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TargetPawnBase.h"
#include "TargetPawn.generated.h"


UCLASS()
class ROLL_API ATargetPawn : public ATargetPawnBase
{
	GENERATED_BODY()
	
public:
	ATargetPawn();
	
protected:
	UFUNCTION()
	virtual void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
