// Fill out your copyright notice in the Description page of Project Settings.

#include "UMGGameMode.h"
#include "UMGCharacter.h"

AUMGGameMode::AUMGGameMode()
{
	DefaultPawnClass = AUMGCharacter::StaticClass();
}
