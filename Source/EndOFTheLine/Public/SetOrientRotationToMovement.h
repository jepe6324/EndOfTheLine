// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SetOrientRotationToMovement.generated.h"

/**
 * 
 */
UCLASS()
class ENDOFTHELINE_API USetOrientRotationToMovement : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

   UFUNCTION(BlueprintCallable, Category = "Lock-On")
   void GetCardinalAxisOfController(AActor* actor, bool on);

};
