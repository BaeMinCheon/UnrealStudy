// Fill out your copyright notice in the Description page of Project Settings.

#include "MVCPlayerController.h"
#include "MVCPlayerState.h"

int32 AMVCPlayerController::GetSpeed()
{
	return MVCPlayerState->GetProperty(TEXT("Speed"));
}

void AMVCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("SpeedUp"), EInputEvent::IE_Pressed, this, &AMVCPlayerController::SpeedUp);
	InputComponent->BindAction(TEXT("SpeedDown"), EInputEvent::IE_Pressed, this, &AMVCPlayerController::SpeedDown);
}

void AMVCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	MVCPlayerState = Cast<AMVCPlayerState>(PlayerState);
}

void AMVCPlayerController::SpeedUp()
{
	MVCPlayerState->AddProperty(TEXT("Speed"));
}

void AMVCPlayerController::SpeedDown()
{
	MVCPlayerState->SubtractProperty(TEXT("Speed"));
}
