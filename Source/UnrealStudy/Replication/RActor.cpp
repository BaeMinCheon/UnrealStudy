// Fill out your copyright notice in the Description page of Project Settings.

#include "RActor.h"
#include "UnrealStudy.h"
#include "Net/UnrealNetwork.h"

void ARActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARActor, Speed);
}

ARActor::ARActor()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	SetReplicates(true);

	Speed = 0.0f;
}

void ARActor::SpeedUp()
{
	if (HasAuthority())
	{
		Speed += 1.0f;
		UE_LOG(LogServer, Warning, TEXT("current speed : %f"), Speed);
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("oops !"));
	}
}

void ARActor::SpeedDown()
{
	if (HasAuthority())
	{
		Speed -= 1.0f;
		UE_LOG(LogServer, Warning, TEXT("current speed : %f"), Speed);
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("oops !"));
	}
}

void ARActor::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("I am server"));
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("I am client"));
	}
}

void ARActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	Location += FVector(Speed * DeltaTime, 0.0f, 0.0f);
	SetActorLocation(Location);
}