// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GetCardinalAxisOfController.generated.h"

/**
 * 
 */
UCLASS()
class ENDOFTHELINE_API UGetCardinalAxisOfController : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

   UFUNCTION(BlueprintPure, Category = "Lock-On")
   static FVector2D GetCardinalAxisOfController(FVector2D vector);
};
