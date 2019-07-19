// Fill out your copyright notice in the Description page of Project Settings.

#include "KCharacterChild.h"
#include "Components/InputComponent.h"

AKCharacterChild::AKCharacterChild()
{
	DynamicMulticastDelegate.AddDynamic(this, &AKCharacterChild::Foo);
}

void AKCharacterChild::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("KAction"), EInputEvent::IE_Pressed, this, &AKCharacterChild::KAction);
}

void AKCharacterChild::BeginPlay()
{
	Super::BeginPlay();

	auto DefaultObject = GetDefault<AKCharacterChild>(AKCharacterChild::StaticClass());
	if (DefaultObject != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), DefaultObject->TestInt);
		UE_LOG(LogTemp, Warning, TEXT("%f"), DefaultObject->TestFloat);
		UE_LOG(LogTemp, Warning, TEXT("%d"), DefaultObject->TestPaths.Num());
	}
}

void AKCharacterChild::BlueprintFuu_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Fuu() using cpp"));
}

void AKCharacterChild::KAction()
{
	DynamicMulticastDelegate.Broadcast();
}

void AKCharacterChild::Foo()
{
	UE_LOG(LogTemp, Warning, TEXT("Foo()"));

	BlueprintFoo();
}
