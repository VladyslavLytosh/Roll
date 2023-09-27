// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BasePawn.h"
#include "TargetPawn.generated.h"


class UBoxComponent;

UCLASS()
class ROLL_API ATargetPawn : public ABasePawn
{
public:
	GENERATED_BODY()
	
	ATargetPawn();
	
	virtual void ChangeColor(const FColor& InColor);
	
	virtual void PostInitializeComponents() override;
	
	virtual void PaintTarget(const FColor& InColor);
	
	virtual void CleanTarget();
	
	FORCEINLINE bool& IsClean() { return bIsClean; };

	FORCEINLINE void SetIsClean(const bool InIsClean) { this->bIsClean = InIsClean; };
	
	FORCEINLINE FColor& GetNewColor() { return NewColor; }; 

	FORCEINLINE void SetNewColor(const FColor& InNewColor) { this->NewColor = InNewColor; };

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
	
private:
	bool bIsClean=true;
	FColor NewColor;
};
