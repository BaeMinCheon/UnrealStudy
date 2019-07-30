// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API ARPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ARPlayerController();

private:
	UFUNCTION(Exec)
	void FindActor();

	UFUNCTION(Exec)
	void SpeedUp();

	UFUNCTION(Exec)
	void SpeedDown();

	FString GetStringFromRole();
	void LogString(FString Message);

	class ARActor* RActor;
};
