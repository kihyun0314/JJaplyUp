// Copyright Epic Games, Inc. All Rights Reserved.

#include "JJaplyUpGameMode.h"
#include "JJaplyUpCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJJaplyUpGameMode::AJJaplyUpGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
