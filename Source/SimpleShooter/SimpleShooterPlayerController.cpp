// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleShooterPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SimpleShooterCharacter.h"



ASimpleShooterPlayerController::ASimpleShooterPlayerController()
{
	bReplicates = true;
}

void ASimpleShooterPlayerController::Tick(float DeltaTime)
{
}

void ASimpleShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(MappingContext);

	ControlledCharacter = CastChecked<ASimpleShooterCharacter>(GetPawn());

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(MappingContext, 0);
}

void ASimpleShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASimpleShooterPlayerController::Move);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ASimpleShooterPlayerController::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ASimpleShooterPlayerController::StopJumping);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASimpleShooterPlayerController::Look);

}

void ASimpleShooterPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ASimpleShooterPlayerController::Jump()
{
	ControlledCharacter->Jump();
}

void ASimpleShooterPlayerController::StopJumping()
{
	ControlledCharacter->StopJumping();
}

void ASimpleShooterPlayerController::Look(const FInputActionValue& InputActionValue)
{
	FVector2D LookAxisValue2D = InputActionValue.Get<FVector2D>();
	
	
	AddYawInput(LookAxisValue2D.X * RotationRate);
	AddPitchInput(LookAxisValue2D.Y * RotationRate);
	
}




