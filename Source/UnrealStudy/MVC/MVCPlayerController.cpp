// Fill out your copyright notice in the Description page of Project Settings.

#include "MVCPlayerController.h"
#include "MVCPlayerState.h"

void AMVCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Count"), EInputEvent::IE_Pressed, this, &AMVCPlayerController::CountUp);
}

void AMVCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	MVCPlayerState = Cast<AMVCPlayerState>(PlayerState);
}

void AMVCPlayerController::CountUp()
{
	MVCPlayerState->AddCount();
}
