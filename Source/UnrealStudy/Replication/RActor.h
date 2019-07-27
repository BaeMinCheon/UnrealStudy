// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RActor.generated.h"

UCLASS()
class UNREALSTUDY_API ARActor : public AActor
{
	GENERATED_BODY()
	
public:
	ARActor();

	UPROPERTY(ReplicatedUsing=OnRep_Speed)
	float Speed;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnRep_Speed();

	class UStaticMeshComponent* StaticMesh;
};
