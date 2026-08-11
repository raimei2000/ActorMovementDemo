#include "Movable.h"

AMovable::AMovable()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(SceneRoot);

	MoveSpeed = 50.0f;
	MaxRange = 500.0f;
	StartLocation = FVector(0.0f, 0.0f, 0.0f);

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovable::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

