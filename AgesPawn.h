// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "AgesPawn.generated.h"

//General Log
DECLARE_LOG_CATEGORY_EXTERN(TempLog, Log, All);

UENUM(BlueprintType)
enum class EInteractionMode : uint8 {
	Standard		UMETA(DisplayName = "Standard"),
	Building		UMETA(DisplayName = "Building"),
	Destructing		UMETA(DisplayName = "Destructing"),
	Pipetting		UMETA(DisplayName = "Pipetting")
};

UCLASS()
class AGES_API AAgesPawn : public APawn
{
	GENERATED_BODY()

// Attributes--------------------------------------------------
public:
	// Sets default values for this pawn's properties
	AAgesPawn();

	// Components----------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UFloatingPawnMovement* Movement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInteractionMode InteractionMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor *Selection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor *Dummy;
	

protected:
	// BeginPlay
	virtual void BeginPlay() override;

// Functions---------------------------------------------------
public:	
	// Tick
	virtual void Tick(float DeltaTime) override;

	// Bind Input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Input Functions
	void Select();
	void Order();
	void MoveRight(float Value);
	void MoveForward(float Value);
	
	// Modes
	void PipetteMode();
	void DestructionMode();
	void BuildMode();

	// Building Dummy
	void RotateDummyCW();
	void RotateDummyCCW();

	// Camera 
	void ResetCamera();
	void DragStart();
	void DragStop();
	void ZoomIn();
	void ZoomOut();
	void RotateCameraStart();
	void RotateCameraStop();

	// Saving & Loading
	void QuickSave();
	void QuickLoad();

	void SpawnBuilding();
	
};
