// Fill out your copyright notice in the Description page of Project Settings.

#include "Ages.h"
#include "AgesStorage.h"

// Constructor
AAgesStorage::AAgesStorage() : Super() {
	
	CartsCur = 1;
	CartsMax = 1;
}



void AAgesStorage::SendTransport() {
	CartsCur--;
}

void AAgesStorage::ReturnTransport() {
	CartsCur++;
}
