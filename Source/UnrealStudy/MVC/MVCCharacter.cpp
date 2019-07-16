
// Fill out your copyright notice in the Description page of Project Settings.

#include "MVCCharacter.h"
#include "MVCPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/NumericLimits.h"

// Sets default values
AMVCCharacter::AMVCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MVCPlayerController = Cast<AMVCPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	GetCharacterMovement()->MaxWalkSpeed = TNumericLimits<float>::Max();
}

// Called when the game starts or when spawned
void AMVCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMVCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMVCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AMVCCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AMVCCharacter::MoveRight);
}

void AMVCCharacter::MoveForward(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue * (float)(MVCPlayerController->GetSpeed()));
}

void AMVCCharacter::MoveRight(float NewAxisValue)
{
	AddMovementInput(GetActorRightVector(), NewAxisValue * (float)(MVCPlayerController->GetSpeed()));
}

