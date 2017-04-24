// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AgesNetwork.generated.h"

class AgesProduction;

UCLASS()
class AGES_API AAgesNetwork : public AActor
{
	GENERATED_BODY()
	
// Attributes--------------------------------------------------
public:	

	// Constructor
	AAgesNetwork();

	TArray<AActor*> Productions;
	TArray<AActor*> Converter;
	TArray<AActor*> Residences;
	TArray<AActor*> Radiators;

// Functions---------------------------------------------------
public:	

	void GetProductionsInRange(float Range, FVector Location, TArray<AActor*>& Temp);

	// Production
	void AddProduction(AActor* ToAdd);
	void RemoveProduction(AActor* ToRemove);
	
	
};
