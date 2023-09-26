// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RollGameMode.generated.h"


class ATargetPawn;

UCLASS()
class ROLL_API ARollGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	FORCEINLINE int32 GetTargetsCount() const { return TargetsCount; };
	
	FORCEINLINE int32 GetCleanersCount() const { return CleanersCount; };

	void OnPaintTarget(ATargetPawn* Target);
	
	void OnCleanTarget(ATargetPawn* Target);
	
protected:
	virtual void BeginPlay() override;
	
private:
	int32 TargetsCount;
	int32 CleanersCount;

	int32 GetNumCleanerTargets() const;
	int32 GetNumAlLTargets() const;

	void CheckWinCondition();
};
