#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Transformable.h"

#include "Movable.generated.h"

UCLASS()
class ACTORMOVEMENTDEMO_API AMovable : public ATransformable
{
	GENERATED_BODY()
	
public:	
	AMovable();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movable|Move")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movable|Move")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movable|Move")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movable|Move")
	float Direction;
	virtual void Tick(float DeltaTime) override;


private:
	float DistanceAccumulation;
};
