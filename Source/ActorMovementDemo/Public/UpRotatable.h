#pragma once

#include "CoreMinimal.h"
#include "Rotatable.h"
#include "UpRotatable.generated.h"

UCLASS()
class ACTORMOVEMENTDEMO_API AUpRotatable : public ARotatable
{
	GENERATED_BODY()
	
public:
	AUpRotatable();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpRotatable|Move")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpRotatable|Move")
	float TimeToDestroy;

	virtual void Tick(float DeltaTime) override;

private:
	float TimeAccumulation;
};
