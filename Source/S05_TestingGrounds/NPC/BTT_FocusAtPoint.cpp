// UnEpicGame Studio Copyrights.

#include "BTT_FocusAtPoint.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"

EBTNodeResult::Type UBTT_FocusAtPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	FVector LookAtTarget = BlackboardComp->GetValueAsVector(TargetLookKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("LookAtTarget = %s"), *LookAtTarget.ToString())
	AIController->SetFocalPoint(LookAtTarget);

	return EBTNodeResult::Succeeded;
}
