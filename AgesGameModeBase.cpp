// Fill out your copyright notice in the Description page of Project Settings.

#include "Ages.h"
#include "AgesGameModeBase.h"

// Constructor




// Transformations--------------------------------------------------------------------------------



// WorldToIndex
int AAgesGameModeBase::WorldToIndex(FVector World) {
	int Index = floor(World.X / TileSize) * Y + floor(World.Y / TileSize);
	return Index;
}
int AAgesGameModeBase::WorldToIndex(FVector2D World) {
	int Index = floor(World.X / TileSize) * Y + floor(World.Y / TileSize);
	return Index;
}

// GridToIndex
int AAgesGameModeBase::GridToIndex(Fint2D Grid)
{
	return 0;
}

// WorldToGrid
Fint2D AAgesGameModeBase::WorldToGrid(FVector World) {
	return Fint2D();
}

// IndexToGrid
Fint2D AAgesGameModeBase::IndexToGrid(int Index) {
	return Fint2D();
}

// IndexToCenter
FVector AAgesGameModeBase::IndexToCenter(int Index) {
	FVector Center = FVector((Index / X + 0.5f) * TileSize, ((Index / X) * X + 0.5f) * TileSize, 0);
	return Center;
}

// GridToCenter
FVector AAgesGameModeBase::GridToCenter(Fint2D Grid)
{
	return FVector();
}

// OffsetsToIndexes
void AAgesGameModeBase::OffsetsToIndexes(FVector2D World, FVector2D *Offsets, int *Indexes, int Length) {
	for (int i = 0; i < Length; i++) 
		Indexes[i] = WorldToIndex(World + Offsets[i]);
}

// WorldToSnap with Even/Odd
FVector2D AAgesGameModeBase::WorldToSnapExE(FVector2D World) {
	FVector2D Snap = FVector2D(FMath::RoundToInt(World.X / TileSize) * TileSize, FMath::RoundToInt(World.Y / TileSize) * TileSize);
	return Snap;
}
FVector2D AAgesGameModeBase::WorldToSnapExO(FVector2D World) {
	FVector2D Snap = FVector2D(FMath::RoundToInt(World.X / TileSize) * TileSize, (FMath::FloorToInt(Snap.Y / TileSize) + 0.5f) * TileSize);
	return Snap;
}
FVector2D AAgesGameModeBase::WorldToSnapOxE(FVector2D World) {
	FVector2D Snap = FVector2D((FMath::FloorToInt(Snap.X / TileSize) + 0.5f) * TileSize, FMath::RoundToInt(World.Y / TileSize) * TileSize);
	return Snap;
}
FVector2D AAgesGameModeBase::WorldToSnapOxO(FVector2D World) {
	FVector2D Snap = FVector2D((FMath::FloorToInt(Snap.X / TileSize) + 0.5f) * TileSize, (FMath::FloorToInt(Snap.Y / TileSize) + 0.5f) * TileSize);
	return Snap;
}



// LoadMap
void AAgesGameModeBase::LoadMap(int NewX, int NewY) {
	X = NewX;
	Y = NewY;
	TileCount = X * Y;
	// Resize Arrays
}

// Pathfinding-----------------------------------------------------------------------------------

// A*
FVector AAgesGameModeBase::FindPath(AActor *Start, AActor *Goal, AActor *Network) {
	TArray<AANode*> OpenList;
	TArray<Fint2D> StartTiles;
	TArray<Fint2D> GoalTiles;
	AANode *CurrentNode;
	// Set Heuristic Target
	Fint2D HeuristicTarget = WorldToGrid(Start->GetActorLocation());

	// Set Start Tiles
		//(AAgesBuilding*)Start

	// Set Goal Tiles


	// Make OpenList


	// Loop
	while (OpenList.Num() != 0) {
		AANode* Min = OpenList[0]; // Findes die Node mit minimalen Kosten
		for (int i = 1; i < OpenList.Num(); i++) {
			if (OpenList[i]->Cost < Min->Cost)
				Min = OpenList[i];
		}
		CurrentNode = Min;
		
		//OpenList.RemoveSingleSwap(CurrentNode);
		// Goal Check
	}

	return FVector();
}



// GetManhattanDistance
int AAgesGameModeBase::GetManhattanDistance(Fint2D Start, Fint2D End) {
	return FMath::Abs(Start.X - End.X) + FMath::Abs(Start.Y - End.Y);
}

// Blocking-----------------------------------------------------------------------------------------

// CheckBlocks
bool AAgesGameModeBase::CheckBlocks(int *Indexes, int Length) {	
	for (int i = 0; i < Length; i++) {
		if (bBlocked[Indexes[i]] == true)
			return true;
	}
	return false;
}
bool AAgesGameModeBase::CheckBlocks(FVector2D World, FVector2D *Offsets, int Length) {
	for (int i = 0; i < Length; i++) {
		if (WorldToIndex(World + Offsets[i])) 
			return true;
	}
	return false;
}
