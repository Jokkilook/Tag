// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "TagPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API ATagPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<class UUserWidget> WBP_Battery;

	UPROPERTY()
	class UUserWidget* Battery;

public:
	virtual void BeginPlay() override;
};
