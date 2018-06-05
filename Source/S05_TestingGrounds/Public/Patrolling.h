// UnEpicGame Studio Copyrights.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Patrolling.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTINGGROUNDS_API UPatrolling : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPatrolling();
	
	TArray<AActor*> GetPatrolPoints() const;

private:
	
	UPROPERTY(EditInstanceOnly, Category = "Patrol")
	TArray<AActor*> PatrolPoints;


};