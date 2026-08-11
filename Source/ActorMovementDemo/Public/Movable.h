#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movable.generated.h"

UCLASS()
class ACTORMOVEMENTDEMO_API AMovable : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovable();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movable|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movable|Components")
	UStaticMeshComponent* StaticMeshComponent;

	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movable|Move")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movable|Move")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movable|Move")
	float MaxRange;
	virtual void Tick(float DeltaTime) override;

};
