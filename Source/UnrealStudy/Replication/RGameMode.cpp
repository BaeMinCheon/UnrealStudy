// Fill out your copyright notice in the Description page of Project Settings.

#include "RGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "RActor.h"
#include "UnrealStudy.h"

ARGameMode::ARGameMode()
{
	RActor = nullptr;
}

void ARGameMode::FindActor()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARActor::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		RActor = Cast<ARActor>(FoundActors[0]);
	}
}

void ARGameMode::SpeedUp()
{
	if (RActor != nullptr)
	{
		RActor->Speed += 5.0f;

		UE_LOG(LogServer, Warning, TEXT("speed is %f"), RActor->Speed);
	}
}

void ARGameMode::SpeedDown()
{
	if (RActor != nullptr)
	{
		RActor->Speed -= 5.0f;
		if (RActor->Speed < 0.0f)
		{
			RActor->Speed = 0.0f;
		}

		UE_LOG(LogServer, Warning, TEXT("speed is %f"), RActor->Speed);
	}
}
