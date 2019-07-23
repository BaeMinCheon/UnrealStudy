// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DCharacter.generated.h"

DECLARE_DELEGATE_OneParam(FDDelegate, FString);
DECLARE_MULTICAST_DELEGATE_OneParam(FDMulticastDelegate, FString);

UCLASS()
class UNREALSTUDY_API ADCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FDDelegate SingleDelegate;

	FDMulticastDelegate MultiDelegate;

private:
	void PrintLog();

	UFUNCTION()
	void Func01(FString Message);

	UFUNCTION()
	void Func02(FString Message);
};
