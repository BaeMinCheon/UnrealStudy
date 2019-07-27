// Fill out your copyright notice in the Description page of Project Settings.

#include "RGameMode.h"
#include "RPlayerController.h"

ARGameMode::ARGameMode()
{
	PlayerControllerClass = ARPlayerController::StaticClass();
}
