// Fill out your copyright notice in the Description page of Project Settings.

#include "DGameMode.h"
#include "DCharacter.h"

ADGameMode::ADGameMode()
{
	DefaultPawnClass = ADCharacter::StaticClass();
}
