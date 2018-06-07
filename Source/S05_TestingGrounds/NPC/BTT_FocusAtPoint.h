// UnEpicGame Studio Copyrights.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_FocusAtPoint.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API UBTT_FocusAtPoint : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
			
		UPROPERTY(EditAnyWhere, Category = "Blackboard")
		struct FBlackboardKeySelector TargetLookKey;
	
};
