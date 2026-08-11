#include "UpDownRotatable.h"

AUpDownRotatable::AUpDownRotatable()
{
	MoveSpeed = 1.0f;
	StartLocation = FVector(0.0f, 0.0f, 0.0f);
	RunningTime = 0.0f;
	MoveRange = 500.0f;

	PrimaryActorTick.bCanEverTick = true;
}

void AUpDownRotatable::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	InitialUpDirection = GetActorUpVector();
}

void AUpDownRotatable::Tick(float DeltaTime)
{
	// Rotate
	Super::Tick(DeltaTime);

	// UpDown(Sin)
	RunningTime += DeltaTime;
	float Offset = MoveRange * FMath::Sin(MoveSpeed * RunningTime);
	SetActorLocation(StartLocation + InitialUpDirection * Offset);
}
