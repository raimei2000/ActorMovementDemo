#include "Movable.h"

AMovable::AMovable()
{
	MoveSpeed = 500.0f;
	MaxRange = 3000.0f;
	DistanceAccumulation = 0.0f;
	Direction = 1.0f;
	StartLocation = FVector(0.0f, 0.0f, 0.0f);

	PrimaryActorTick.bCanEverTick = true;
}

void AMovable::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

void AMovable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float DeltaDistance = MoveSpeed * DeltaTime;
	FVector DeltaVector = Direction * GetActorUpVector() * DeltaDistance;
	DistanceAccumulation += DeltaDistance;
	if (DistanceAccumulation >= MaxRange)
	{
		Direction = FMath::Clamp(-1.0f * Direction, -1.0f, 1.0f);
		DistanceAccumulation = 0.0f;
	}
	AddActorWorldOffset(DeltaVector);
}
