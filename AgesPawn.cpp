// Fill out your copyright notice in the Description page of Project Settings.

#include "Ages.h"
#include "AgesPawn.h"

//General Log
DEFINE_LOG_CATEGORY(TempLog);

// Constructor
AAgesPawn::AAgesPawn() {
 	// Enable Tick
	PrimaryActorTick.bCanEverTick = true;

	// Components-----------------------------------------------------------------------------
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(Scene);
	SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 0.0f;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	this->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	

	InteractionMode = EInteractionMode::Standard;

}

// BeginPlay
void AAgesPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Tick
void AAgesPawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	FHitResult Result;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, Result);
	
	switch(InteractionMode) {
	case 0:	// Standard
		break;
	case 1:	// Building 
		if (!Dummy->IsValidLowLevel()) // Does Dummy NOT exist?
			return;
		
		//UGameplayStatics::GetGameMode
		break;
	case 2: // Destructing
		break;
	case 3: // Pipetting
		break;
	
	}
}

// Bind Input
void AAgesPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Main Input
	InputComponent->BindAction("Select", IE_Released, this, &AAgesPawn::Select);
	InputComponent->BindAction("Order", IE_Released, this, &AAgesPawn::Order);
	InputComponent->BindAxis("MoveRight", this, &AAgesPawn::MoveRight);
	InputComponent->BindAxis("MoveForward", this, &AAgesPawn::MoveForward);

	// Modes
	InputComponent->BindAction("PipetteMode", IE_Released, this, &AAgesPawn::PipetteMode);
	InputComponent->BindAction("DestructionMode", IE_Released, this, &AAgesPawn::DestructionMode);
	InputComponent->BindAction("BuildMode", IE_Released, this, &AAgesPawn::BuildMode);

	// Building Dummy
	InputComponent->BindAction("RotateDummyCW", IE_Released, this, &AAgesPawn::RotateDummyCW);
	InputComponent->BindAction("RotateDummyCCW", IE_Released, this, &AAgesPawn::RotateDummyCCW);

	// Camera
	InputComponent->BindAction("ResetCamera", IE_Released, this, &AAgesPawn::ResetCamera);
	InputComponent->BindAction("Drag", IE_Released, this, &AAgesPawn::DragStart);
	InputComponent->BindAction("Drag", IE_Released, this, &AAgesPawn::DragStop);
	InputComponent->BindAction("ZoomIn", IE_Released, this, &AAgesPawn::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Released, this, &AAgesPawn::ZoomOut);
	InputComponent->BindAction("RotateCamera", IE_Released, this, &AAgesPawn::RotateCameraStart);
	InputComponent->BindAction("RotateCamera", IE_Released, this, &AAgesPawn::RotateCameraStop);

	// Saving & Loading
	InputComponent->BindAction("QuickSave", IE_Released, this, &AAgesPawn::QuickSave);
	InputComponent->BindAction("QUickLoad", IE_Released, this, &AAgesPawn::QuickLoad);
}

// Input Functions-----------------------------------------------------------------------
void AAgesPawn::Select() {
	FHitResult Result;
	switch(InteractionMode) {
	case 0:	// Standard
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, Result);
		if(Result.bBlockingHit == false)
			return;
		UE_LOG(TempLog, Warning, TEXT("TROLOLOL"));
		if (Selection) {
			// Deselect //			
		}
		Selection = Result.GetActor();
		// Select//
		return;

	case 1:	// Building
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, Result);
		if (Result.bBlockingHit == false)
			return;
		SpawnBuilding();
		return;
	case 2:	// Destructing
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, Result);
		if (Result.bBlockingHit == false)
			return;
		// Destruct //
		return;

	case 3:	// Pipetting
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, Result);
		if (Result.bBlockingHit == false)
			return;
		// Change Interaction to Building//
		return;
	}
}
void AAgesPawn::Order() {
}
void AAgesPawn::MoveRight(float Value) {
	Movement->AddInputVector(FRotationMatrix(this->GetActorRotation()).GetScaledAxis(EAxis::Y) * Value, false);
}
void AAgesPawn::MoveForward(float Value) {
	Movement->AddInputVector(FRotationMatrix(this->GetActorRotation()).GetScaledAxis(EAxis::X) * Value, false);
}

// Modes
void AAgesPawn::PipetteMode() {
}
void AAgesPawn::DestructionMode() {
}
void AAgesPawn::BuildMode() {
}

// Building Dummy
void AAgesPawn::RotateDummyCW() {
}
void AAgesPawn::RotateDummyCCW() {
}

// Camera
void AAgesPawn::ResetCamera() {
	this->SetActorRotation(FRotator(0,0,0));
}
void AAgesPawn::DragStart() {
}
void AAgesPawn::DragStop() {
}
void AAgesPawn::ZoomIn() {
}
void AAgesPawn::ZoomOut() {
}
void AAgesPawn::RotateCameraStart() {
}
void AAgesPawn::RotateCameraStop() {
}

// Saving & Loading
void AAgesPawn::QuickSave() {
}
void AAgesPawn::QuickLoad() {
}

void AAgesPawn::SpawnBuilding() {
	return;
}