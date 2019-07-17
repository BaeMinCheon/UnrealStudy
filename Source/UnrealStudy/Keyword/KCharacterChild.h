// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Keyword/KCharacterParent.h"
#include "KCharacterChild.generated.h"

/**
 * 
 */
UCLASS(config=KCharacter)
class UNREALSTUDY_API AKCharacterChild : public AKCharacterParent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(config)
	int32 TestInt;

	UPROPERTY(config)
	float TestFloat;
	
	UPROPERTY(config)
	TArray<FSoftObjectPath> TestPaths;

protected:
	void BeginPlay() override;
};