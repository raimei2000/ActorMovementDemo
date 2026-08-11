#include "Rotatable.h"

ARotatable::ARotatable()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(SceneRoot);

	RotationSpeed = FVector(0.0f, 90.0f, 0.0f);
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatable::BeginPlay()
{
	Super::BeginPlay();	
}

void ARotatable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator DeltaRotator(RotationSpeed.X * DeltaTime,
		                  RotationSpeed.Y * DeltaTime,
		                  RotationSpeed.Z * DeltaTime);
	AddActorLocalRotation(DeltaRotator);
}
