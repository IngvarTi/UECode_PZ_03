// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PawnCollision"));
	RootComponent = PawnCollision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" BaseMesh "));
	Mesh->SetupAttachment(RootComponent);
	Mesh->OnComponentHit.AddDynamic(this, &ATurret::OnComponentHit);

	Health = 100.f;
	KillSkore = 15.f;
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATurret::Destroyed()
{
	Super::Destroyed();
	if (OnTurretKilled.IsBound())
	{
		OnTurretKilled.Broadcast();
	}
}

bool ATurret::Die(float Health)
{
	if (Health <= 0)
	return true;
	return false;
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurret::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		Health -= 10.f;
		UE_LOG(LogTemp, Warning, TEXT("Health is - %f"), Health);

		if (Die(Health))
		{
			this->Destroy();
			UE_LOG(LogTemp, Warning, TEXT("Died"));
		}
	}
}

