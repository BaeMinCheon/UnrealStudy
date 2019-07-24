// Fill out your copyright notice in the Description page of Project Settings.

#include "DCharacter.h"
#include <Components/InputComponent.h>

ADCharacter::ADCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SingleDelegate.BindUFunction(this, FName("Func01"));
	SingleDelegate.BindUFunction(this, FName("Func02"));

	MultiDelegate.AddUFunction(this, FName("Func01"));
	MultiDelegate.AddUFunction(this, FName("Func02"));

	DynamicDelegate01.BindUFunction(this, FName("Func01"));
	DynamicDelegate01.BindUFunction(this, FName("Func02"));

	DynamicMultiDelegate.AddDynamic(this, &ADCharacter::Func01);
	DynamicMultiDelegate.AddDynamic(this, &ADCharacter::Func02);
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
	//SingleDelegate.Execute(TEXT("Single Delegate"));
	//MultiDelegate.Broadcast(TEXT("Multi Delegate"));
	//DynamicDelegate01.Execute(TEXT("Dynamic Delegate 01"));
	//DynamicDelegate02.Execute(TEXT("Dynamic Delegate 02"));
	DynamicMultiDelegate.Broadcast(TEXT("Dynamic Multi Delegate"));
}

void ADCharacter::Func01(FString Message)
{
	UE_LOG(LogTemp, Warning, TEXT("Func01() : %s"), *Message);
}

void ADCharacter::Func02(FString Message)
{
	UE_LOG(LogTemp, Warning, TEXT("Func02() : %s"), *Message);
}
