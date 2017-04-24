// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "AgesBuilding.generated.h"

class AAgesNetwork;

UENUM(BlueprintType)
enum class EShape : uint8 {
	S1x1		UMETA(DisplayName = "1x1"),
	S2x2		UMETA(DisplayName = "2x2"),
	S3x3		UMETA(DisplayName = "3x3"),
	S4x4		UMETA(DisplayName = "4x4"),
	S5x5		UMETA(DisplayName = "5x5"),
	S6x6		UMETA(DisplayName = "6x6")
};

UCLASS()
class AGES_API AAgesBuilding : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Constructors
	AAgesBuilding();
	AAgesBuilding(FName NewName);

	// Attributes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building")
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	EShape Shape;
	TArray<AAgesNetwork*> Networks;

	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticMesh")
	UStaticMeshComponent *StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skeletal´Mesh")
	USkeletalMeshComponent *SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indicator")
	UStaticMeshComponent *Indicator;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ShowOutline();
	void HideOutline();
	
	
};
