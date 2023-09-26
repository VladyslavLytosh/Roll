// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BasePawn.h"
#include "PlayerPawn.generated.h"


class UArrowComponent;
class ATargetPawn;
class URollPlayerComponent;


UCLASS()
class ROLL_API APlayerPawn : public ABasePawn
{
	GENERATED_BODY()
	
public:
	APlayerPawn();
	
protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Input, meta = (AllowPrivateAccess = "true"))
	URollPlayerComponent* RollPlayerComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = true))
	USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = true))
	UCameraComponent* CameraComponent;

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Sound, meta = (AllowPrivateAccess = true))
	USoundBase* PaintSound;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = VFX, meta = (AllowPrivateAccess = true))
	UParticleSystem* PaintEmitter;
};
