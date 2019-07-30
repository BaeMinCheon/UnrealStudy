// Fill out your copyright notice in the Description page of Project Settings.

#include "RCharacter.h"
#include "UnrealStudy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/SWindow.h"
#include "Kismet/GameplayStatics.h"

ARCharacter::ARCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SetActorEnableCollision(false);
	GetCharacterMovement()->GravityScale = 0.0f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	Camera->SetupAttachment(SpringArm);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATICMESH"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CartonBox01(TEXT("/Game/IndustryPropsPack6/Meshes/SM_CartonBox01.SM_CartonBox01"));
	StaticMesh->SetStaticMesh(SM_CartonBox01.Object);
}

void ARCharacter::BeginPlay()
{
	Super::BeginPlay();

	LogString(TEXT("BeginPlay"));
}

void ARCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &ARCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &ARCharacter::MoveRight);
}

void ARCharacter::MoveForward(float NewAxisValue)
{
	AddActorLocalOffset(GetActorForwardVector() * NewAxisValue);
	if (NewAxisValue != 0.0f)
	{
		Server_MoveForward(NewAxisValue);
	}
}

void ARCharacter::MoveRight(float NewAxisValue)
{
	AddActorLocalOffset(GetActorRightVector() * NewAxisValue);
	if (NewAxisValue != 0.0f)
	{
		Server_MoveRight(NewAxisValue);
	}
}

void ARCharacter::Server_MoveForward_Implementation(float NewAxisValue)
{
	LogString(TEXT("Server_MoveForward"));

	AddActorLocalOffset(GetActorForwardVector() * NewAxisValue);
}

bool ARCharacter::Server_MoveForward_Validate(float NewAxisValue)
{
	if ((-1.0f <= NewAxisValue) && (NewAxisValue <= 1.0f))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ARCharacter::Server_MoveRight_Implementation(float NewAxisValue)
{
	LogString(TEXT("Server_MoveRight"));

	AddActorLocalOffset(GetActorRightVector() * NewAxisValue);
}

bool ARCharacter::Server_MoveRight_Validate(float NewAxisValue)
{
	if ((-1.0f <= NewAxisValue) && (NewAxisValue <= 1.0f))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ARCharacter::CallClientLog(int32 Index)
{
	ARCharacter* Character = Cast<ARCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), Index));
	if (Character != nullptr)
	{
		Character->Client_Log();
	}
	else
	{
		LogString(TEXT("wrong index"));
	}
}

void ARCharacter::Client_Log_Implementation()
{
	LogString(TEXT("Client_Log"));
}

void ARCharacter::CallMulticastLog()
{
	Multicast_Log();
}

void ARCharacter::Multicast_Log_Implementation()
{
	LogString(TEXT("Multicast_Log"));
}

FString ARCharacter::GetStringFromRole()
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

void ARCharacter::LogString(FString Message)
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
