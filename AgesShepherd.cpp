// Fill out your copyright notice in the Description page of Project Settings.

#include "Ages.h"
#include "AgesShepherd.h"


// Sets default values
AAgesShepherd::AAgesShepherd()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAgesShepherd::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAgesShepherd::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAgesShepherd::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

