// Fill out your copyright notice in the Description page of Project Settings.

#include "Ages.h"
#include "AgesNetwork.h"


// Constructor
AAgesNetwork::AAgesNetwork() {
 	// Disable Tick
	PrimaryActorTick.bCanEverTick = false;
}


// Functions----------------------------------------------------------------------------------

void AAgesNetwork::GetProductionsInRange(float Range, FVector Location, TArray<AActor*>& Temp)  {
	//Productions.
	Temp.Reserve(Productions.Num()); // RESERVIERE SPEICHER
	for (int i = 0; i < Productions.Num(); i++) {	
		if(Productions[i])
		if((Productions[i]->GetActorLocation() - Location).Size() <= Range)
			continue;
		Temp.Add(Productions[i]);
	}	
}

// Production
void AAgesNetwork::AddProduction(AActor* ToAdd)
{
	Productions.Add(ToAdd);
}
void AAgesNetwork::RemoveProduction(AActor* ToRemove)
{
	Productions.Remove(ToRemove);
}

