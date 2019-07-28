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

	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("Character::BeginPlay() by %s with %s"), *GetName(), *GetTextFromRole());
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("Character::BeginPlay() by %s with %s"), *GetName(), *GetTextFromRole());
	}
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
	UE_LOG(LogTemp, Warning, TEXT("Server_MoveForward() by %s"), *GetName());

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
	UE_LOG(LogTemp, Warning, TEXT("Server_MoveRight() by %s"), *GetName());

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

void ARCharacter::CallLog()
{
	Client_Log();
}

void ARCharacter::Client_Log_Implementation()
{
	UE_LOG(LogClient, Warning, TEXT("Client_Log() by %s with %s"), *GetName(), *GetTextFromRole());
}

FString ARCharacter::GetTextFromRole()
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