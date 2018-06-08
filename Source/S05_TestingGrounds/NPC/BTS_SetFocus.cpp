// Fill out your copyright notice in the Description page of Project Settings.

#include "BTS_SetFocus.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"


void UBTS_SetFocus::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	UObject* FocusTarget = BlackboardComp->GetValueAsObject(TargetFocus.SelectedKeyName);
	if (!FocusTarget)
	{
		UE_LOG(LogTemp, Warning, TEXT("FocusTarget = Gameplay"))
		AIController->ClearFocus(EAIFocusPriority::Gameplay);
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("LookAtTarget = %s"), *FocusTarget->GetName())
	AIController->SetFocus(Cast<AActor>(FocusTarget));
	return;
}
