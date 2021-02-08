// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "TestGtaphBlueprintStyle.h"

class FTestGtaphBlueprintCommands : public TCommands<FTestGtaphBlueprintCommands>
{
public:

	FTestGtaphBlueprintCommands()
		: TCommands<FTestGtaphBlueprintCommands>(TEXT("TestGtaphBlueprint"), NSLOCTEXT("Contexts", "TestGtaphBlueprint", "TestGtaphBlueprint Plugin"), NAME_None, FTestGtaphBlueprintStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};