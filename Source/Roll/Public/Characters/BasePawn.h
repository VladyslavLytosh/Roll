// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCapsuleComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS(Abstract)
class ROLL_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* PawnMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Style, meta = (AllowPrivateAccess = true))
	UMaterialInterface* PawnMaterial;
	
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Style, meta = (AllowPrivateAccess = true))
	FColor PawnColor;
};
