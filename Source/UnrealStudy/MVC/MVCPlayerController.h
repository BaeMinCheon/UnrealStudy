// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MVCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API AMVCPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	int32 GetSpeed();

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	
private:
	void SpeedUp();
	void SpeedDown();

	class AMVCPlayerState* MVCPlayerState;
};
