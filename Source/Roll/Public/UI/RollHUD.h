// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RollHUD.generated.h"


UCLASS(Abstract)
class ROLL_API ARollHUD : public AHUD
{
	GENERATED_BODY()

public:
	void ToggleVictoryScreenWidget() const;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = GameHUD, meta = (AllowPrivateAccess = true))
	TSubclassOf<UUserWidget> GameHUDClass;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = GameHUD, meta = (AllowPrivateAccess = true))
	TSubclassOf<UUserWidget> VictoryScreenClass;

private:
	UPROPERTY()
	UUserWidget* GameHUDWidget;
	UPROPERTY()
	UUserWidget* VictoryScreenWidget;
};
