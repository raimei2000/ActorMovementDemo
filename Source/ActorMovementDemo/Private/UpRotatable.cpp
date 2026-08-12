#include "UpRotatable.h"

AUpRotatable::AUpRotatable()
{
    MoveSpeed = 500.f;
    TimeToDestroy = 20.0f;
    TimeAccumulation = 0.0f;
    RotationSpeed = FVector(10.0f, -20.0f, 0.0f);

    PrimaryActorTick.bCanEverTick = true;
}

void AUpRotatable::BeginPlay()
{
    Super::BeginPlay();

    RotationSpeed.Z = 0.0f;
}

void AUpRotatable::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AddActorWorldOffset(GetActorUpVector() * MoveSpeed * DeltaTime);
    TimeAccumulation += DeltaTime;
    if (TimeAccumulation >= TimeToDestroy)
    {
        Destroy();
    }
}