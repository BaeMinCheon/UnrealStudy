// Fill out your copyright notice in the Description page of Project Settings.

#include "RActor.h"
#include "UnrealStudy.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"

ARActor::ARActor()
{
	PrimaryActorTick.bCanEverTick = true;

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
	
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("Actor::BeginPlay() by %s"), *GetName());
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("Actor::BeginPlay() by %s"), *GetName());
	}
}

void ARActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += FVector(Speed * DeltaTime, 0.0f, 0.0f);
	SetActorLocation(NewLocation);
}

