// Fill out your copyright notice in the Description page of Project Settings.


#include "TagPlayerController.h"

void ATagPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!WBP_Battery) return;
	if (!Battery) Battery = CreateWidget<UUserWidget>(this, WBP_Battery);
	if (!Battery->IsInViewport()) Battery->AddToViewport();
}
