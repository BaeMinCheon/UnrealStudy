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

	UPROPERTY(config, BlueprintReadOnly, Category="Property|Int", VisibleAnywhere)
	int32 TestInt;

	UPROPERTY(config, BlueprintReadWrite, Category="Property|Float", VisibleDefaultsOnly)
	float TestFloat;
	
	UPROPERTY(config)
	TArray<FSoftObjectPath> TestPaths;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FKDynamicMulticastDelegate DynamicMulticastDelegate;

protected:
	void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BlueprintFoo();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BlueprintFuu();

private:
	void KAction();

	UFUNCTION(BlueprintCallable)
	void Foo();

	UFUNCTION(BlueprintPure)
	int GetPure();

	UFUNCTION(Exec)
	void Faa();

	UFUNCTION(Exec)
	void FaaWithInt(int Number);
};