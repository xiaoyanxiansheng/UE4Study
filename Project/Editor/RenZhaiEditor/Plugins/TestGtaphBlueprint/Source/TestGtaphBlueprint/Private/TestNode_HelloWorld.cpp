// Fill out your copyright notice in the Description page of Project Settings.


#include "TestNode_HelloWorld.h"

UTestNode_HelloWorld::UTestNode_HelloWorld() 
{

}

void UTestNode_HelloWorld::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, "HelloWorldInput", FName(), TEXT("In"));
	CreatePin(EGPD_Output, "HelloWorldInput", FName(), TEXT("out"));
	CreatePin(EGPD_MAX, "HelloWorldInput", FName(), TEXT("Max"));
}

FText UTestNode_HelloWorld::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString("Hello World");
}
