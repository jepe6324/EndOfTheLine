// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TestPawn.generated.h"

class ATestActor;

UCLASS()
class ENDOFTHELINE_API ATestPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATestPawn();

	ATestActor* target_;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float amount);
	void MoveRight(float amount);
	void Turn(float amount);
	void LookUp(float amount);
	void LockOn();

	class UFloatingPawnMovement* floatingPawnMovement_;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* staticMesh_;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UCameraComponent* camera_;

	UPROPERTY(EditAnywhere, Category = "Components")
	class USpringArmComponent* cameraArm_;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
