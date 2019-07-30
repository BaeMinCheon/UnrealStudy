// Fill out your copyright notice in the Description page of Project Settings.

#include "RActor.h"
#include "Net/UnrealNetwork.h"
#include "UnrealStudy.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/SWindow.h"

void ARActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARActor, Speed);
}

ARActor::ARActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	SetActorEnableCollision(false);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATICMESH"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BOX_02(TEXT("/Game/IndustryPropsPack6/Meshes/SM_Box02.SM_Box02"));
	StaticMesh->SetStaticMesh(SM_BOX_02.Object);

	Speed = 0.0f;
}

void ARActor::BeginPlay()
{
	Super::BeginPlay();
	
	LogString(TEXT("BeginPlay"));
}

void ARActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += FVector(Speed * DeltaTime, 0.0f, 0.0f);
	SetActorLocation(NewLocation);
}

void ARActor::OnRep_Speed()
{
	LogString(FString::Printf(TEXT("speed replicated, which is %f"), Speed));
}

FString ARActor::GetStringFromRole()
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

void ARActor::LogString(FString Message)
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

