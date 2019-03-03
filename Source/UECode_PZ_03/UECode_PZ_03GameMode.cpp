// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UECode_PZ_03GameMode.h"
#include "UECode_PZ_03HUD.h"
#include "UECode_PZ_03Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "UECode_PZ_03/Turret.h"

void AUECode_PZ_03GameMode::BeginPlay()
{
	TArray<AActor *> turretActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), turretActors);
	for (AActor * turretActor : turretActors)
	{
		ATurret * turret = Cast<ATurret>(turretActor);
		if (turret)
		{
			turret->OnTurretKilled.AddUFunction(this, "OnTurretDestroy");
		}
	}
}

AUECode_PZ_03GameMode::AUECode_PZ_03GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUECode_PZ_03HUD::StaticClass();
}

void AUECode_PZ_03GameMode::OnTurretDestroy()
{
	Score += 10;
	UE_LOG(LogTemp, Warning, TEXT("Score is - %f"), Score);
}
