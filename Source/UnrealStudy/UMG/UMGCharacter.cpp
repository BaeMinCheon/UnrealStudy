// Fill out your copyright notice in the Description page of Project Settings.

#include "UMGCharacter.h"
#include "Components/WidgetComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AUMGCharacter::AUMGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TestWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("TEST"));
	TestWidget->SetupAttachment(RootComponent);
	TestWidget->SetRelativeLocation(FVector(180.0f, 0.0f, 0.0f));
	TestWidget->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_Test(TEXT("/Game/Resources/Blueprints/TestWidget.TestWidget_C"));
	if (UI_Test.Succeeded())
	{
		TestWidget->SetWidgetClass(UI_Test.Class);
		TestWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}
}

// Called when the game starts or when spawned
void AUMGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUMGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUMGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

