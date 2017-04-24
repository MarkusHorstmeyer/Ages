// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface {
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class AGES_API IInteractionInterface {
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	void Select();
	void Destruct();
	
};
