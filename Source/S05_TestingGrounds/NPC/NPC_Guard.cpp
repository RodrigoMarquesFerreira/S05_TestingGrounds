// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_Guard.h"


// Sets default values
ANPC_Guard::ANPC_Guard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANPC_Guard::SetAimState(bool NewState)
{
	bIsAiming = NewState;
	return ;
}

// Called when the game starts or when spawned
void ANPC_Guard::BeginPlay()
{
	Super::BeginPlay();
	bIsAiming = false;
}

// Called every frame
void ANPC_Guard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_Guard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ANPC_Guard::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	if (CurrentHealth > 0)
	{
		CurrentHealth -= DamageAmount;
		if (CurrentHealth <= 0) 
		{ 
			CurrentHealth = 0; 
			DetachFromControllerPendingDestroy();
		}
		
		UE_LOG(LogTemp, Warning, TEXT("Guard Health = %d, type of damage = %d"), CurrentHealth, DamageEvent.GetTypeID())
	}
	
	return 0.0f;
}

