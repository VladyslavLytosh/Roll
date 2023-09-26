// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BasePawn.h"
#include "TargetPawn.generated.h"


class UBoxComponent;

UCLASS()
class ROLL_API ATargetPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	ATargetPawn();
	
	virtual void Paint(const FColor& Color);
	
	virtual void PostInitializeComponents() override;
	
	UPROPERTY()
	bool bClean=true;
	
	UPROPERTY()
	FColor NewColor;
	
protected:
	UPROPERTY()
	FTimerHandle ForceTimer;

	UPROPERTY(EditAnywhere,Category = Movement)
	float Speed=700.f;
	UPROPERTY(EditAnywhere,Category = Movement)
	float MoveRate=1.f;

	UFUNCTION()
	virtual void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void MovePawn();
};
