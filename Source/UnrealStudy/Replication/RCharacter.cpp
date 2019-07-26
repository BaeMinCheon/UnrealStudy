// Fill out your copyright notice in the Description page of Project Settings.

#include "RCharacter.h"
#include "UnrealStudy.h"
#include "Components/InputComponent.h"

ARCharacter::ARCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 0.0f;
}

void ARCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("Character::BeginPlay() by %s"), *GetName());
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("Character::BeginPlay() by %s"), *GetName());
	}
}

void ARCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	Location += FVector(Speed * DeltaTime, 0.0f, 0.0f);
	SetActorLocation(Location);
}

void ARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("SpeedUp"), EInputEvent::IE_Pressed, this, &ARCharacter::SpeedUp);
	PlayerInputComponent->BindAction(TEXT("SpeedDown"), EInputEvent::IE_Pressed, this, &ARCharacter::SpeedDown);
}

void ARCharacter::SpeedUp()
{
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("speed is %f in server"), Speed);

		Speed += 1.0f;
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("speed is %f in client"), Speed);
	}
}

void ARCharacter::SpeedDown()
{
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("speed is %f in server"), Speed);

		Speed -= 1.0f;
		if (Speed < 0.0f)
		{
			Speed = 0.0f;
		}
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("speed is %f in client"), Speed);
	}
}

