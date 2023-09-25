// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BasePawn.h"
#include "TargetPawnBase.generated.h"


class UBoxComponent;

UCLASS()
class ROLL_API ATargetPawnBase : public ABasePawn
{
	GENERATED_BODY()

public:
	ATargetPawnBase();
	
	virtual void Paint(const FColor& Color);
	
	virtual void BeginPlay() override;
	
	UPROPERTY(Transient)
	bool bClean=true;
	
	UPROPERTY(Transient)
	FColor NewColor;
	
protected:
	FTimerHandle ForceTimer;
};
