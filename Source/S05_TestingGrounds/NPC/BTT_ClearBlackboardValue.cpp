// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_ClearBlackboardValue.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTT_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	BlackboardComp->ClearValue(ValueKey.SelectedKeyName);
	return EBTNodeResult::Succeeded;
}
