// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATestPawn::ATestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	floatingPawnMovement_ = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	staticMesh_ = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");

	cameraArm_ = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	cameraArm_->SetupAttachment(staticMesh_);
	cameraArm_->TargetArmLength = 500.f;

	camera_ = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	//camera_->SetRelativeLocation(FVector(-500.f, 0.f, 0.f));
	camera_->SetupAttachment(cameraArm_);

	SetRootComponent(staticMesh_);

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATestPawn::MoveForward(float amount)
{
	floatingPawnMovement_->AddInputVector(GetActorForwardVector() * amount);
}

void ATestPawn::MoveRight(float amount)
{
	floatingPawnMovement_->AddInputVector(GetActorRightVector() * amount);
}

void ATestPawn::Turn(float amount)
{
	AddControllerYawInput(amount);
}

void ATestPawn::LookUp(float amount)
{
	AddControllerPitchInput(amount);
}

// Called every frame
void ATestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATestPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATestPawn::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ATestPawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ATestPawn::LookUp);
}

