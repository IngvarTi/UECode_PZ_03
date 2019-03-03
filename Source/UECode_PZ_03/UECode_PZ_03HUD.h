// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UECode_PZ_03HUD.generated.h"

UCLASS()
class AUECode_PZ_03HUD : public AHUD
{
	GENERATED_BODY()

public:
	AUECode_PZ_03HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

