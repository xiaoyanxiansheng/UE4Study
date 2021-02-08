// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGraphSchema.h"
#include <Editor\UnrealEd\Public\ScopedTransaction.h>

#define LOCTEXT_NAMESPACE "TextGraphSchema"

void UTestGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	TSharedPtr<FTestGraphSchemaAction> NewNodeAction(new 
		FTestGraphSchemaAction(
			LOCTEXT("A","Grap Node"),
			LOCTEXT("Desc", "MyTestAA"),
			LOCTEXT("NewGraphText", "Add a Node"),
			0
		));

	NewNodeAction->NodeHelloWorld = NewObject<UTestNode_HelloWorld>(ContextMenuBuilder.OwnerOfTemporaries);
	ContextMenuBuilder.AddAction(NewNodeAction);
	// ContextMenuBuilder.AddAction(NewNodeAction);
}

UEdGraphNode* FTestGraphSchemaAction::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	UEdGraphNode* UEdResultNode = nullptr;

	if (NodeHelloWorld != nullptr) 
	{
		const FScopedTransaction Transaction(LOCTEXT("FF", "Hello:NewNode"));
		ParentGraph->Modify();
		if (FromPin != nullptr) 
		{
			FromPin->Modify();
		}
		NodeHelloWorld->Rename(NULL, ParentGraph);
		ParentGraph->AddNode(NodeHelloWorld,true,bSelectNewNode);

		NodeHelloWorld->CreateNewGuid();
		NodeHelloWorld->PostPlacedNewNode();
		NodeHelloWorld->AllocateDefaultPins();
		NodeHelloWorld->AutowireNewNode(FromPin);

		NodeHelloWorld->NodePosX = Location.X;
		NodeHelloWorld->NodePosY = Location.Y;

		NodeHelloWorld->SetFlags(RF_Transactional);
	}
	return UEdResultNode;
}
#undef LOCTEXT_NAMESPACE