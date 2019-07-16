// Fill out your copyright notice in the Description page of Project Settings.

#include "MVCPlayerState.h"
#include "Engine/Engine.h"

AMVCPlayerState::AMVCPlayerState()
{
	Counter = 0;
}

void AMVCPlayerState::AddCount()
{
	Counter += 1;

	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::FromInt(Counter));
	}
}
