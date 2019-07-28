// Fill out your copyright notice in the Description page of Project Settings.

#include "RPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "RActor.h"
#include "UnrealStudy.h"

ARPlayerController::ARPlayerController()
{
	RActor = nullptr;

	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("PlayerController::BeginPlay() by %s"), *GetName());
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("PlayerController::BeginPlay() by %s"), *GetName());
	}
}

void ARPlayerController::FindActor()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARActor::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		RActor = Cast<ARActor>(FoundActors[0]);

		if (RActor != nullptr)
		{
			LogText(TEXT("actor has been found"));
		}
	}
}

void ARPlayerController::SpeedUp()
{
	if (RActor != nullptr)
	{
		RActor->Speed += 5.0f;

		LogSpeed(TEXT("increased"));
	}
	else
	{
		LogText(TEXT("exec FindActor first"));
	}
}

void ARPlayerController::SpeedDown()
{
	if (RActor != nullptr)
	{
		RActor->Speed -= 5.0f;
		if (RActor->Speed < 0.0f)
		{
			RActor->Speed = 0.0f;
		}

		LogSpeed(TEXT("decreased"));
	}
	else
	{
		LogText(TEXT("exec FindActor first"));
	}
}

void ARPlayerController::LogText(FString Message)
{
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("%s"), *Message);
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("%s"), *Message);
	}
}

void ARPlayerController::LogSpeed(FString Message)
{
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("speed has been %s, which is %f"), *Message, RActor->Speed);
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("speed has been %s, which is %f"), *Message, RActor->Speed);
	}
}
