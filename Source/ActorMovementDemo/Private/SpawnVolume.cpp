#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "UpRotatable.h"

ASpawnVolume::ASpawnVolume()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetCollisionProfileName(TEXT("NoCollision"));
	BoxComponent->SetupAttachment(SceneRoot);

	SpawnDelay = 0.25f;

	PrimaryActorTick.bCanEverTick = false;
}

void ASpawnVolume::BeginPlay()
{
	BoxExtent = BoxComponent->GetScaledBoxExtent();
	StartLocation = SceneRoot->GetComponentLocation();
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnVolume::SpawnActorAtRandomLocation, SpawnDelay, true);
}

FVector ASpawnVolume::GetRandomPointInVolume() const
{
    return StartLocation + FVector(FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		                           FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		                           FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z));
}

void ASpawnVolume::SpawnActorAtRandomLocation() const
{
	if (TargetToSpawn)
	{
		AUpRotatable* Instance = GetWorld()->SpawnActor<AUpRotatable>(TargetToSpawn, GetRandomPointInVolume(), FRotator::ZeroRotator);
		Instance->MoveSpeed = FMath::FRandRange(800.0f, 1100.0f);
		Instance->RotationSpeed = FVector(FMath::FRandRange(-20.0f, 20.0f), FMath::FRandRange(-20.0f, 20.0f), 0.0f);
	}
}