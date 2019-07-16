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

	void AddCount();
	
protected:
	int32 Counter;
};
