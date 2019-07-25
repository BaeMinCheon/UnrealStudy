// Fill out your copyright notice in the Description page of Project Settings.

#include "RActor.h"




ARActor::ARActor()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void ARActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	Location += FVector(5.0f * DeltaTime, 0.0f, 0.0f);
	SetActorLocation(Location);
}
