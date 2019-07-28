// Fill out your copyright notice in the Description page of Project Settings.

#include "RActor.h"
#include "Net/UnrealNetwork.h"
#include "UnrealStudy.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"

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
	
	/*if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("Actor::BeginPlay() by %s"), *GetName());
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("Actor::BeginPlay() by %s"), *GetName());
	}*/
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
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("speed has been replicated, which is %f"), Speed);
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("speed has been replicated, which is %f"), Speed);
	}
}

