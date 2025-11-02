// Copyright Epic Games, Inc. All Rights Reserved.

#include "TagGameMode.h"
#include "TagCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATagGameMode::ATagGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
