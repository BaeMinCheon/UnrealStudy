// Fill out your copyright notice in the Description page of Project Settings.

#include "RCharacter.h"
#include <Components/InputComponent.h>

ARCharacter::ARCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("SpeedUp"), EInputEvent::IE_Pressed, this, &ARCharacter::SpeedUp);
	PlayerInputComponent->BindAction(TEXT("SpeedDown"), EInputEvent::IE_Pressed, this, &ARCharacter::SpeedDown);
}

void ARCharacter::SpeedUp()
{
	;
}

void ARCharacter::SpeedDown()
{
	;
}

