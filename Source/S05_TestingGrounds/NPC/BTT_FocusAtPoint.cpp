// UnEpicGame Studio Copyrights.

#include "BTT_FocusAtPoint.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"

EBTNodeResult::Type UBTT_FocusAtPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	UObject* LookAtTarget = BlackboardComp->GetValueAsObject(TargetLookKey.SelectedKeyName);
	if (!LookAtTarget) 
	{
		UE_LOG(LogTemp, Warning, TEXT("LookAtTarget = null")) 
		AIController->ClearFocus(EAIFocusPriority::Move);
		return EBTNodeResult::Failed; 
	}
	UE_LOG(LogTemp, Warning, TEXT("LookAtTarget = %s"), *LookAtTarget->GetName())
	AIController->SetFocus(Cast<AActor>(LookAtTarget));
	

	return EBTNodeResult::Succeeded;
}
