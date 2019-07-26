// Fill out your copyright notice in the Description page of Project Settings.

#include "RCharacter.h"
#include "UnrealStudy.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

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

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BOX_02(TEXT("/Game/IndustryPropsPack6/Meshes/SM_Box02.SM_Box02"));
	StaticMesh->SetStaticMesh(SM_BOX_02.Object);

	Speed = 0.0f;
}

void ARCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("Character::BeginPlay() by %s"), *GetName());
	}
	else
	{
		UE_LOG(LogClient, Warning, TEXT("Character::BeginPlay() by %s"), *GetName());
	}
}

void ARCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += FVector(Speed * DeltaTime, 0.0f, 0.0f);
	SetActorLocation(NewLocation);
}

void ARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("SpeedUp"), EInputEvent::IE_Pressed, this, &ARCharacter::SpeedUp);
	PlayerInputComponent->BindAction(TEXT("SpeedDown"), EInputEvent::IE_Pressed, this, &ARCharacter::SpeedDown);
}

void ARCharacter::SpeedUp()
{
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("speed is %f"), Speed);

		Speed += 1.0f;
	}
}

void ARCharacter::SpeedDown()
{
	if (HasAuthority())
	{
		UE_LOG(LogServer, Warning, TEXT("speed is %f"), Speed);

		Speed -= 1.0f;
		if (Speed < 0.0f)
		{
			Speed = 0.0f;
		}
	}
}

