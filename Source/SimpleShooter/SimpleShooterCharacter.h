// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SimpleShooterCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SIMPLESHOOTER_API ASimpleShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASimpleShooterCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Camera", Meta = (AllowPrivateAcces = true))
	USpringArmComponent* CameraBoom;
	

	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Camera", Meta = (AllowPrivateAcces = true))
	UCameraComponent* FallowCamera;
};
