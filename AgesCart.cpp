// Fill out your copyright notice in the Description page of Project Settings.

#include "Ages.h"
#include "AgesCart.h"


// Constructors
AAgesCart::AAgesCart() {
	PrimaryActorTick.bCanEverTick = true;
}
AAgesCart::AAgesCart(FVector* NewPath, int NewLength, bool bFlip, AActor* NewStorage, AActor* NewProduction) {
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	if (NewLength == 1) {}		// für pathlength = 1 skippe bewegung
	LastIndex = 0;					// Set StartIndexes
	NextIndex = 1;
	Length = NewLength;
	Path = NewPath;
	if (bFlip == true) {}			// should the path be reversed?
	CalcDirection();
	
	Storage = NewStorage;
	Production = NewProduction;
	bMove = true;
	Speed = 100.0f;
	Traveled = 0.0f;
	bReverse = false;
	WaitTime = 1.0f;
}

// Tick
void AAgesCart::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	float DeltaSpeed = FMath::Clamp(DeltaTime, 0.0f, 0.033333f);
	if (bMove == false)
		return;
	Traveled += DeltaSpeed;
	if (Traveled < 100.0f) {
		this->AddActorWorldOffset(Direction * Speed * DeltaSpeed, false);
		return;
	}	
	this->SetActorLocation(Path[NextIndex], false);
	if (bReverse == false && Length - 1 == NextIndex) {
		LastIndex = NextIndex;
		NextIndex--;
		CalcDirection();
		bReverse = true;
		bMove = false;
		Traveled = 0.0f;
		// TIMER HERE
		return;////////////////
	}
	else if(bReverse == true && 0 == NextIndex) {
		bMove = false; // Disable the Tick?
		// TIMER HERE 
		Production->IsValidLowLevel();


		return;
	}
	else {
		LastIndex = NextIndex;
		if (bReverse == true) { NextIndex = LastIndex - 1; }
		else { NextIndex = LastIndex + 1; }
		CalcDirection();
		// Fix Overhang
		Traveled -= 100;
		this->AddActorWorldOffset(Direction * Traveled, false);
		return;
	}
}

void AAgesCart::OneTilePath() {
	// TIMER

	//TIMER
	this->Destroy();
}

// Calc Direction
void AAgesCart::CalcDirection() {
	Direction = Path[1] - Path[0];
	Direction.Normalize(0.001f);
	this->SetActorRotation(FMatrix(Direction, FVector::ZeroVector, FVector::ZeroVector, FVector::ZeroVector).Rotator(), ETeleportType::TeleportPhysics);
}

