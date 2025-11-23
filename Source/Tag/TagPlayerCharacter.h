// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TagCharacter.h"
#include "Components/SpotLightComponent.h"
#include "TagPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API ATagPlayerCharacter : public ATagCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LightSwitchAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpotLightComponent* SpotLightComponent;

	bool LightOnOff = true;

	UPROPERTY(VisibleAnywhere, Category = "Battery")
	float BatteryValue;

	float MaxBatteryValue = 10000000.f;
	float SubtractScale = 100.f;
	
	FORCEINLINE void SubtractBatteryValue(float value) { BatteryValue -= value; };
	
public:
	ATagPlayerCharacter();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float BatteryPercent() { return BatteryValue/MaxBatteryValue; };
	
protected:
	void LightSwitch(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
};
