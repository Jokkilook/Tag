// Fill out your copyright notice in the Description page of Project Settings.


#include "TagPlayerCharacter.h"

ATagPlayerCharacter::ATagPlayerCharacter()
{
	SpotLightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SpotLightComponent->SetupAttachment(GetFirstPersonCameraComponent());
	SpotLightComponent->SetIntensity(25000);

	BatteryValue = MaxBatteryValue;
}

void ATagPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (LightOnOff) SubtractBatteryValue(DeltaTime * SubtractScale);
	if (BatteryValue <= 0.f)
	{
		LightOnOff = false;
		SpotLightComponent->SetVisibility(LightOnOff);
	}
}

void ATagPlayerCharacter::LightSwitch(const FInputActionValue& Value)
{
	if (BatteryValue <= 0.f) return;
	LightOnOff = !LightOnOff;
	
	if (SpotLightComponent)
	{
		SpotLightComponent->SetVisibility(LightOnOff);
	}
}

void ATagPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(LightSwitchAction, ETriggerEvent::Started, this, &ATagPlayerCharacter::LightSwitch);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}
