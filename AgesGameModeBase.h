// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "Runtime/Core/Public/Math/Vector2D.h"
#include "AgesBuilding.h"
#include "ANode.h"
#include "AgesGameModeBase.generated.h"



UCLASS()
class AGES_API AAgesGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// Constants-----------------------------------------------------------------------
	const float TileSize = 100.0f;

	// Offsets
	const FVector2D BlockOffsets1x1[1];
	const FVector2D BlockOffsets2x2[4];
	const FVector2D BlockOffsets3x3[9];
	const FVector2D BlockOffsets4x4[16];
	const FVector2D BlockOffsets5x5[25];
	const FVector2D BlockOffsets6x6[36];

	const FVector2D BlockOffsets3x5[15];
	const FVector2D BlockOffsets5x3[15];

	const FVector2D ConnectorOffsets1x1[4];
	const FVector2D ConnectorOffsets2x2[8];
	const FVector2D ConnectorOffsets3x3[12];
	const FVector2D ConnectorOffsets4x4[16];
	const FVector2D ConnectorOffsets5x5[20];
	const FVector2D ConnectorOffsets6x6[24];

	const FVector2D ConnectorOffsets3x5[16];
	const FVector2D ConnectorOffsets5x3[16];

	

	// Layers-----------------------------------------------------------------------
	bool bBlocked[1];
	AActor *Networks[1];
	AActor *Buildings[1];
	AActor *Connectors[1];
	AActor *Usage[1];

private:
	int X, Y, TileCount;




public:
	

	// Transformations	-----------------------------------------------------------------------
	int WorldToIndex(FVector World);
	int WorldToIndex(FVector2D World);
	int GridToIndex(Fint2D Grid);
	
	Fint2D WorldToGrid(FVector World);
	Fint2D IndexToGrid(int Index);

	FVector IndexToCenter(int Index);
	FVector GridToCenter(Fint2D Grid);

	void OffsetsToIndexes(FVector2D World, FVector2D *Offsets, int *Indexes, int Length); // works on the array pointer target
	
	// WorldToSnap with Even/Odd
	FVector2D WorldToSnapExE(FVector2D World);		
	FVector2D WorldToSnapExO(FVector2D World);
	FVector2D WorldToSnapOxE(FVector2D World);
	FVector2D WorldToSnapOxO(FVector2D World);

	// Load Map----------------------------------------------------------------------------------------
	void LoadMap(int NewX, int NewY); // takes map structure with x y , ...

	// Pathfinding----------------------------------------------------------------------------------
	
	// A*
	FVector FindPath(AActor *Start, AActor *Goal, AActor *Network);
	

	// Manhattan Distance
	int GetManhattanDistance(Fint2D Start, Fint2D End);

	// Blocking-----------------------------------------------------------------------
	
	// CheckBlocks
	bool CheckBlocks(int *Indexes, int Length);
	bool CheckBlocks(FVector2D World, FVector2D *Offsets, int Length);

	// BlockIndexes
	//void BlockIndexes(int * Indexes, int Length);
};
