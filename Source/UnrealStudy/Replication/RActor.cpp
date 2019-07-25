// Fill out your copyright notice in the Description page of Project Settings.

#include "RActor.h"




ARActor::ARActor()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	Speed = 0.0f;
}

void ARActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		Location += FVector(Speed * DeltaTime, 0.0f, 0.0f);
		SetActorLocation(Location);
	}
}
