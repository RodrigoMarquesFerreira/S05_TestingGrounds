// UnEpicGame Studio Copyrights.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API UBTT_ChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(EditAnyWhere, Category = "Blackboard")
	struct FBlackboardKeySelector IndexKey;
	UPROPERTY(EditAnyWhere, Category = "Blackboard")
	struct FBlackboardKeySelector NextWaypointKey;

	TArray<AActor*> PatrolPoints;
};
