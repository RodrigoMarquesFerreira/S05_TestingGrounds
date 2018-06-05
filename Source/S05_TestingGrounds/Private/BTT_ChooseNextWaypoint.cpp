// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_ChooseNextWaypoint.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UBTT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//TODO  protect against empty patrol routes
	
	//Get the Patrol Points
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	PatrolPoints = PatrollingGuard->Waypoints;

	//Set next Waypoint
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, PatrolPoints[Index]);
	
	//Cycle the index
	int32 NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	//UE_LOG(LogTemp, Warning,TEXT("Current index = %i"), Index)
	return EBTNodeResult::Succeeded;
}
