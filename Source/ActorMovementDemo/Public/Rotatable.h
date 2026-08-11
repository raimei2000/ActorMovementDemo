#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rotatable.generated.h"

UCLASS()
class ACTORMOVEMENTDEMO_API ARotatable : public AActor
{
	GENERATED_BODY()
	
public:
	ARotatable();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rotatable|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rotatable|Components")
	UStaticMeshComponent* StaticMeshComponent;

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotatable|Rotation")
	FVector RotationSpeed;
	virtual void Tick(float DeltaTime) override;
};
