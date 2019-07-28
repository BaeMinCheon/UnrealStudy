// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RCharacter.generated.h"

UCLASS()
class UNREALSTUDY_API ARCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float NewAxisValue);
	void MoveRight(float NewAxisValue);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveForward(float NewAxisValue);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveRight(float NewAxisValue);

	class USpringArmComponent* SpringArm;
	class UCameraComponent* Camera;
	class UStaticMeshComponent* StaticMesh;
};
