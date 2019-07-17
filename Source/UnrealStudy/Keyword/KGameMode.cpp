// Fill out your copyright notice in the Description page of Project Settings.

#include "KGameMode.h"
#include "KCharacterChild.h"

AKGameMode::AKGameMode()
{
	DefaultPawnClass = AKCharacterChild::StaticClass();
}
