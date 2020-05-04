// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VectorCWAngle2D.generated.h"

/**
 * 
 */
UCLASS()
class ENDOFTHELINE_API UVectorCWAngle2D : public UBlueprintFunctionLibrary
{
   GENERATED_BODY()

   UFUNCTION(BlueprintPure, Category = "Lock-On")
   static float VectorCWAngle2D(FVector a, FVector b);
   static float VectorCWAngle2D(FVector2D a, FVector b);


   UFUNCTION(BlueprintPure, Category = "Lock-On")
      static float SwitchTargetAngleScore(float angle);

   UFUNCTION(BlueprintPure, Category = "Lock-On")
      static float AimRightGunScore(FVector a, FVector b, FVector2D controllerCardinal);
};

