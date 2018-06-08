// Fill out your copyright notice in the Description page of Project Settings.

#include "BTS_LastSeenLocation.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"

void UBTS_LastSeenLocation::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	UObject* TargetObject = BlackboardComp->GetValueAsObject(Target.SelectedKeyName);
	if (IsValid(TargetObject))
	{
		FVector Location = Cast<AActor>(TargetObject)->GetActorLocation();
		BlackboardComp->SetValueAsVector(LastLocation.SelectedKeyName, Location);
		return;
		
	}
	else
	{
			return;
	}
	
}
