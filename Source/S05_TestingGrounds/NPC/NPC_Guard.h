// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC_Guard.generated.h"

UCLASS()
class S05_TESTINGGROUNDS_API ANPC_Guard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_Guard();

	UFUNCTION(BlueprintCallable, Category ="Aim" )
	void SetAimState(bool NewState);


	UPROPERTY(BlueprintReadOnly, Category = "Aim")
	bool bIsAiming;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser);
	UFUNCTION(BlueprintPure, Category = "Health")
	bool IsDead();

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 MaxHealth = 100;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	int32 CurrentHealth = MaxHealth;
};
