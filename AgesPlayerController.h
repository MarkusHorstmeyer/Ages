// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "AgesPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AGES_API AAgesPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	float Storage[100];
	
	
	


public:
	// UserWidgets
	void ShowStartMenu();
	void ShowMain();
	void ShowLoadingScreen();


};
