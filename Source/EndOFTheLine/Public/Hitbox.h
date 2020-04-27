// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hitbox.generated.h"

UENUM(BlueprintType)
enum class EHitboxEnum : uint8
{
	BH_STRIKE UMETA(DisplayName = "Strike")
};

UCLASS()
class ENDOFTHELINE_API AHitbox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHitbox();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
	EHitboxEnum hitboxType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
	FVector hitboxLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
