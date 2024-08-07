// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SimpleShooterPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;
class ASimpleShooterCharacter;
struct FInputActionValue;

UCLASS()
class SIMPLESHOOTER_API ASimpleShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASimpleShooterPlayerController();
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;


	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<ASimpleShooterCharacter> ControlledCharacter;

	void Move(const FInputActionValue& InputActionValue);
	void Jump();
	void StopJumping();
	void Look(const FInputActionValue& InputActionValue);

	UPROPERTY(EditAnywhere, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	float RotationRate = 1.f;

	UPROPERTY(EditAnywhere, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 1.f;

	
};
