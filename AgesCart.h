// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AgesCart.generated.h"


UCLASS()
class AGES_API AAgesCart : public AActor
{
	GENERATED_BODY()

//Attributes--------------------------------------------------
public:	
	// Constructors
	AAgesCart();
	AAgesCart(FVector* NewPath, int NewLength, bool bFlip, AActor* NewStorage, AActor* NewProduction);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StaticMesh")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY()
	float Speed;
	UPROPERTY()
	float WaitTime;
	
private:
	int LastIndex;
	int NextIndex;
	int Length;

	bool bMove;
	bool bReverse;

	float Traveled;

	AActor* Storage;
	AActor* Production;
	
	FVector* Path;
	FVector Direction;

// Functions--------------------------------------------------
public:	
	// Tick
	virtual void Tick(float DeltaTime) override;

	void OneTilePath();
	void CalcDirection();
	
};
