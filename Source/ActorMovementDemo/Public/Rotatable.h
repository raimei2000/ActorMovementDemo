#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Transformable.h"

#include "Rotatable.generated.h"

UCLASS()
class ACTORMOVEMENTDEMO_API ARotatable : public ATransformable
{
	GENERATED_BODY()
	
public:
	ARotatable();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotatable|Rotation")
	FVector RotationSpeed;

public:
	virtual void Tick(float DeltaTime) override;
};
