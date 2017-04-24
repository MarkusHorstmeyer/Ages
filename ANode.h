// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ANode.generated.h"

UCLASS()
class AGES_API AANode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Constructor
	AANode();
	AANode(Fint2D NewPosition);
	
	int Cost;
	Fint2D Position;
	//ANode Predecessor;
};
