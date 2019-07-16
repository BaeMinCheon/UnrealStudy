// Fill out your copyright notice in the Description page of Project Settings.

#include "MVCGameMode.h"
#include "MVCCharacter.h"
#include "MVCPlayerController.h"
#include "MVCPlayerState.h"

AMVCGameMode::AMVCGameMode()
{
	DefaultPawnClass = AMVCCharacter::StaticClass();
	PlayerControllerClass = AMVCPlayerController::StaticClass();
	PlayerStateClass = AMVCPlayerState::StaticClass();
}
