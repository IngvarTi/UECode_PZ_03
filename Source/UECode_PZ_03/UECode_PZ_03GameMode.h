// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UECode_PZ_03/Turret.h"
#include "UECode_PZ_03GameMode.generated.h"

UCLASS(minimalapi)
class AUECode_PZ_03GameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	AUECode_PZ_03GameMode();

	UPROPERTY()
	float Score;

	UFUNCTION()
	void OnTurretDestroy();
};



