// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGtaphBlueprintCommands.h"

#define LOCTEXT_NAMESPACE "FTestGtaphBlueprintModule"

void FTestGtaphBlueprintCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "TestGtaphBlueprint", "Bring up TestGtaphBlueprint window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
