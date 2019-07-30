// Fill out your copyright notice in the Description page of Project Settings.

#include "RPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "RActor.h"
#include "UnrealStudy.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/SWindow.h"

ARPlayerController::ARPlayerController()
{
	RActor = nullptr;
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
			LogString(TEXT("actor has been found"));
		}
	}
}

void ARPlayerController::SpeedUp()
{
	if (RActor != nullptr)
	{
		RActor->Speed += 5.0f;

		LogString(FString::Printf(TEXT("speed increased, which is %f"), RActor->Speed));
	}
	else
	{
		LogString(TEXT("exec FindActor first"));
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

		LogString(FString::Printf(TEXT("speed decreased, which is %f"), RActor->Speed));
	}
	else
	{
		LogString(TEXT("exec FindActor first"));
	}
}

FString ARPlayerController::GetStringFromRole()
{
	FString ReturnValue;

	switch (Role)
	{
	case ROLE_Authority:
		ReturnValue = TEXT("Authority");
		break;

	case ROLE_AutonomousProxy:
		ReturnValue = TEXT("AutonomousProxy");
		break;

	case ROLE_SimulatedProxy:
		ReturnValue = TEXT("SimulatedProxy");
		break;

	default:
		ReturnValue = TEXT("NaN");
		break;
	}

	return ReturnValue;
}

void ARPlayerController::LogString(FString Message)
{
	FString ActorName = GetName();
	FString ActorRole = GetStringFromRole();
	FString WindowTitle;
	if (GEngine->GameViewport != nullptr)
	{
		WindowTitle = GEngine->GameViewport->GetWindow()->GetTitle().ToString();
	}
	else
	{
		WindowTitle = TEXT("Server");
	}

	FString Log = FString::Printf(TEXT("[%s] by [%s] with [%s] in [%s]"), *Message, *ActorName, *ActorRole, *WindowTitle);
	GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::White, Log);
	/*if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("%s"), *Log);
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("%s"), *Log);
	}*/
}