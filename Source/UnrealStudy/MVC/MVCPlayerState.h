// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MVCPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API AMVCPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AMVCPlayerState();

	int32 GetProperty(FString Key);
	void AddProperty(FString Key);
	void SubtractProperty(FString Key);

protected:
	TMap<FString, int32> PropertyMap;
};
