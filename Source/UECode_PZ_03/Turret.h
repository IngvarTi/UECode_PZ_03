// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Turret.generated.h"

DECLARE_EVENT(ATurret, FOnTurretKilled);

UCLASS()
class UECODE_PZ_03_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UFUNCTION()
	bool Die(float Health);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	float KillSkore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	UStaticMeshComponent * Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	UBoxComponent* PawnCollision;

	FOnTurretKilled OnTurretKilled;

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};


