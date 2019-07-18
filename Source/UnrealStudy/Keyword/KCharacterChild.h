// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Keyword/KCharacterParent.h"
#include "KCharacterChild.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FKDynamicMulticastDelegate);

/**
 * 
 */
UCLASS(config=KCharacter)
class UNREALSTUDY_API AKCharacterChild : public AKCharacterParent
{
	GENERATED_BODY()
	
public:
	AKCharacterChild();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(config)
	int32 TestInt;

	UPROPERTY(config)
	float TestFloat;
	
	UPROPERTY(config)
	TArray<FSoftObjectPath> TestPaths;

	UPROPERTY(BlueprintAssignable)
	FKDynamicMulticastDelegate DynamicMulticastDelegate;

protected:
	void BeginPlay() override;

private:
	void KAction();

	UFUNCTION()
	void Foo();
};