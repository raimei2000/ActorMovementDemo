#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Transformable.generated.h"

UCLASS()
class ACTORMOVEMENTDEMO_API ATransformable : public AActor
{
	GENERATED_BODY()
	
public:
	ATransformable();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transformable|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transformable|Components")
	UStaticMeshComponent* StaticMeshComponent;
};
