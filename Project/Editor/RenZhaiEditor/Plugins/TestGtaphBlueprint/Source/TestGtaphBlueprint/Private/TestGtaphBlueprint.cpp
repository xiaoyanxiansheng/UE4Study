// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGtaphBlueprint.h"
#include "TestGtaphBlueprintStyle.h"
#include "TestGtaphBlueprintCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "TestGraphSchema.h"

static const FName TestGtaphBlueprintTabName("TestGtaphBlueprint");

#define LOCTEXT_NAMESPACE "FTestGtaphBlueprintModule"

void FTestGtaphBlueprintModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FTestGtaphBlueprintStyle::Initialize();
	FTestGtaphBlueprintStyle::ReloadTextures();

	FTestGtaphBlueprintCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTestGtaphBlueprintCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTestGtaphBlueprintModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FTestGtaphBlueprintModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TestGtaphBlueprintTabName, FOnSpawnTab::CreateRaw(this, &FTestGtaphBlueprintModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTestGtaphBlueprintTabTitle", "TestGtaphBlueprint"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FTestGtaphBlueprintModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FTestGtaphBlueprintStyle::Shutdown();

	FTestGtaphBlueprintCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TestGtaphBlueprintTabName);
}

TSharedRef<SDockTab> FTestGtaphBlueprintModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FTestGtaphBlueprintModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("TestGtaphBlueprint.cpp"))
		);

	GraphObject = NewObject<UEdGraph>();
	GraphObject->Schema = UTestGraphSchema::StaticClass();
	GraphObject->AddToRoot();

	GraphEditorSlate = SNew(SGraphEditor).GraphToEdit(GraphObject);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//SNew(STextBlock)
				//.Text(WidgetText)
				GraphEditorSlate.ToSharedRef()
			]
		];
}

void FTestGtaphBlueprintModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(TestGtaphBlueprintTabName);
}

void FTestGtaphBlueprintModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FTestGtaphBlueprintCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FTestGtaphBlueprintCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestGtaphBlueprintModule, TestGtaphBlueprint)