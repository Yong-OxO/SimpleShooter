// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleShooterCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASimpleShooterCharacter::ASimpleShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.f;
	CameraBoom->bUsePawnControlRotation = true;

	FallowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FallowCamera"));
	FallowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	// Socket이라는 특별한 이름 지시자를 지정하면 스프링암 끝에 자동으로 붙는다.
	FallowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = true;
}


// Called when the game starts or when spawned
void ASimpleShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASimpleShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

