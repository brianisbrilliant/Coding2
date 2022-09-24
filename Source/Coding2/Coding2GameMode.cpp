// Copyright Epic Games, Inc. All Rights Reserved.

#include "Coding2GameMode.h"
#include "Coding2Character.h"
#include "UObject/ConstructorHelpers.h"

ACoding2GameMode::ACoding2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
