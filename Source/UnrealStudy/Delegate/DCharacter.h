// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DCharacter.generated.h"

DECLARE_DELEGATE_OneParam(FDDelegate, FString);
DECLARE_MULTICAST_DELEGATE_OneParam(FDMulticastDelegate, FString);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDDynamicDelegate, FString, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDDynamicMulticastDelegate, FString, Message);

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

	UPROPERTY(BlueprintReadWrite)
	FDDynamicDelegate DynamicDelegate01;

	UPROPERTY(BlueprintReadWrite)
	FDDynamicDelegate DynamicDelegate02;

	FDDynamicMulticastDelegate DynamicMultiDelegate;

private:
	void PrintLog();

	UFUNCTION()
	void Func01(FString Message);

	UFUNCTION()
	void Func02(FString Message);
};
