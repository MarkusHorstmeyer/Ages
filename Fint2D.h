#pragma once

#include "Fint2D.generated.h"

// UStructs--------------------------------------------
USTRUCT(BlueprintType)
struct Fint2D {

	GENERATED_BODY()

	UPROPERTY()
	int X;
	UPROPERTY()
	int Y;

	// Constructors
	Fint2D() {
		X = 0;
		Y = 0;
	}
	Fint2D(int NewX, int NewY) {
		X = NewX;
		Y = NewY;
	}

	// Operator +
	FORCEINLINE Fint2D operator+(const Fint2D Other) {
		return Fint2D(X + Other.X, Y + Other.Y);
	}

};

