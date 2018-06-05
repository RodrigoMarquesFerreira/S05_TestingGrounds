// UnEpicGame Studio Copyrights.

#include "BTT_ChooseNextWaypoint.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Patrolling.h"

EBTNodeResult::Type UBTT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//Get the Patrol Points
	APawn* ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	UPatrolling* PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolling>();
	//Protect against no Patrol Route Component
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	PatrolPoints = PatrolRoute->GetPatrolPoints();
	//Protect against no Patrol Route Component
	if (PatrolPoints.Num() == 0 ) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("The guard: %s is missing patrol points"), *ControlledPawn->GetName())

		return EBTNodeResult::Failed;
	}

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
