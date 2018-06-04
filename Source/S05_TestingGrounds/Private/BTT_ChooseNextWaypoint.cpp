// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_ChooseNextWaypoint.h"

EBTNodeResult::Type UBTT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning,TEXT("C++ Task"))
	return EBTNodeResult::Succeeded;
}
