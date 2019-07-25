// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "RActor.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API ARActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	ARActor();

protected:
	virtual void Tick(float DeltaTime) override;
};
