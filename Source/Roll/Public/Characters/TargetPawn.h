// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BasePawn.h"
#include "Gameplay/Paintable.h"
#include "TargetPawn.generated.h"


class UBoxComponent;

UCLASS()
class ROLL_API ATargetPawn : public ABasePawn, public IPaintable
{
	GENERATED_BODY()

public:
	ATargetPawn();
	
	virtual void Paint(const FColor& Color) override;
	
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = true))
	UBoxComponent* BoxComponent;
	
	FTimerHandle ForceTimer;
};
