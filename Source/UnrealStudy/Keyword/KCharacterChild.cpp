// Fill out your copyright notice in the Description page of Project Settings.

#include "KCharacterChild.h"




void AKCharacterChild::BeginPlay()
{
	auto DefaultObject = GetDefault<AKCharacterChild>(AKCharacterChild::StaticClass());
	if (DefaultObject != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), DefaultObject->TestInt);
		UE_LOG(LogTemp, Warning, TEXT("%f"), DefaultObject->TestFloat);
		UE_LOG(LogTemp, Warning, TEXT("%d"), DefaultObject->TestPaths.Num());
	}
}
