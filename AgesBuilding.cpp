// Fill out your copyright notice in the Description page of Project Settings.

#include "Ages.h"
#include "AgesBuilding.h"


// Constructors
AAgesBuilding::AAgesBuilding() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Components
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;

	Indicator = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Indicator"));
	Indicator->SetupAttachment(RootComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
}
AAgesBuilding::AAgesBuilding(FName NewName) {
	PrimaryActorTick.bCanEverTick = true;
	Name = NewName;
}

// Begin Play
void AAgesBuilding::BeginPlay() {
	Super::BeginPlay();
}

// Tick
void AAgesBuilding::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

