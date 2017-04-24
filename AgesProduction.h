// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AgesBuilding.h"
#include "AgesProduction.generated.h"

/**
 * 
 */
UCLASS()
class AGES_API AAgesProduction : public AAgesBuilding
{
	GENERATED_BODY()

	
public:
	void Produce();
	void CallTransport();
	
};
