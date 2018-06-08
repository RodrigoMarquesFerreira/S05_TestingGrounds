// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_SetFocus.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API UBTS_SetFocus : public UBTService
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnyWhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetFocus;

protected:
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
