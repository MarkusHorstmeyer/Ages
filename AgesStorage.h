// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AgesBuilding.h"
#include "AgesStorage.generated.h"

/**
 * 
 */
UCLASS()
class AGES_API AAgesStorage : public AAgesBuilding
{
	GENERATED_BODY()
		
public:
	// Constructor
	AAgesStorage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storage")
	int CartsCur;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Storage")
	int CartsMax;

public:
	void SendTransport();
	void ReturnTransport();
	
};
