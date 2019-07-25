// Fill out your copyright notice in the Description page of Project Settings.

#include "RActor.h"
#include "UnrealStudy.h"

ARActor::ARActor()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	Speed = 0.0f;
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
}
