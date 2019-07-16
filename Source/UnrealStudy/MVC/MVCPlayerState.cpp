// Fill out your copyright notice in the Description page of Project Settings.

#include "MVCPlayerState.h"
#include "Engine/Engine.h"


AMVCPlayerState::AMVCPlayerState()
{
	PropertyMap.Add(TEXT("Speed"), 0);
}

int32 AMVCPlayerState::GetProperty(FString Key)
{
	if (PropertyMap.Find(Key) != nullptr)
	{
		return PropertyMap[Key];
	}
	else
	{
		return -1;
	}
}

void AMVCPlayerState::AddProperty(FString Key)
{
	if (PropertyMap.Find(Key) != nullptr)
	{
		PropertyMap[Key] += 1;
		
		if (GEngine != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::FromInt(PropertyMap[Key]));
		}
	}
}

void AMVCPlayerState::SubtractProperty(FString Key)
{
	if (PropertyMap.Find(Key) != nullptr)
	{
		PropertyMap[Key] -= 1;
		if (PropertyMap[Key] < 0)
		{
			PropertyMap[Key] = 0;
		}

		if (GEngine != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::FromInt(PropertyMap[Key]));
		}
	}
}
