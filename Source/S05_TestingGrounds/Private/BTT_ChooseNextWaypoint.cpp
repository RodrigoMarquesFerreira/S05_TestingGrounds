// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_ChooseNextWaypoint.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning,TEXT("Current index = %i"), index)
	return EBTNodeResult::Succeeded;
}
