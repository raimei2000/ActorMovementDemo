#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;
class AUpRotatable;

UCLASS()
class ACTORMOVEMENTDEMO_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:
	ASpawnVolume();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn|Components")
	UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn|Timer")
	float SpawnDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn|Spawn")
	TSubclassOf<AUpRotatable> TargetToSpawn;

	FVector GetRandomPointInVolume() const;
	void SpawnActorAtRandomLocation() const;

	FTimerHandle SpawnTimerHandle;

	virtual void BeginPlay() override;

private:
	FVector BoxExtent;
	FVector StartLocation;
};
