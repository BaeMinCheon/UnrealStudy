// Fill out your copyright notice in the Description page of Project Settings.

#include "DCharacter.h"
#include <Components/InputComponent.h>

ADCharacter::ADCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SingleDelegate.BindUFunction(this, FName("Func01"));
	SingleDelegate.BindUFunction(this, FName("Func02"));
}

void ADCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("DAction"), EInputEvent::IE_Pressed, this, &ADCharacter::PrintLog);
}

void ADCharacter::PrintLog()
{
	SingleDelegate.Execute(TEXT("Single Delegate"));
}

void ADCharacter::Func01(FString Message)
{
	UE_LOG(LogTemp, Warning, TEXT("Func01() : %s"), *Message);
}

void ADCharacter::Func02(FString Message)
{
	UE_LOG(LogTemp, Warning, TEXT("Func02() : %s"), *Message);
}
