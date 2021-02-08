// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphEditor.h"
#include "TestNode_HelloWorld.generated.h"
/**
 * 
 */
UCLASS(MinimalAPI)
class UTestNode_HelloWorld : public UEdGraphNode
{
	GENERATED_BODY()
public:
	UTestNode_HelloWorld();

	// 创建针脚
	virtual void AllocateDefaultPins() override;

	// 显示节点名字
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
};
