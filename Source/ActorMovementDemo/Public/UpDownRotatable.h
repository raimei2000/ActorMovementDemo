#pragma once

#include "CoreMinimal.h"
#include "Transformable.h"

#include "Rotatable.h"

#include "UpDownRotatable.generated.h"

UCLASS()
class ACTORMOVEMENTDEMO_API AUpDownRotatable : public ARotatable
{
	GENERATED_BODY()
	
public:
	AUpDownRotatable();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpDownRotatable|Move")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpDownRotatable|Move")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpDownRotatable|Move")
	float MoveRange;

	virtual void Tick(float DeltaTime) override;

private:
	float RunningTime;
	FVector InitialUpDirection;
};
