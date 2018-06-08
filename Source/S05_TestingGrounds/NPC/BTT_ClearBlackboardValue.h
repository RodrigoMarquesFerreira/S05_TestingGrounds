// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_ClearBlackboardValue.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API UBTT_ClearBlackboardValue : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnyWhere, Category = "Blackboard")
	struct FBlackboardKeySelector ValueKey;
	
	
};
