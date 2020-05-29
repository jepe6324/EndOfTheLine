// Fill out your copyright notice in the Description page of Project Settings.


#include "GetCardinalAxisOfController.h"

FVector2D UGetCardinalAxisOfController::GetCardinalAxisOfController(FVector2D vector)
{
   FVector2D ret = {0.0f, 0.0f};
   if (fabsf(vector.X) > fabsf(vector.Y)) // This means they are aiming either to the left or to the right
   {
      if (vector.X >= 0.0f)
      { // Right
         ret.X = 1.0f;
      }
      else
      { // Left
         ret.X = -1.0f;
      }
   }
   else // This means they are aiming either forward or backwards
   {
      if (vector.Y >= 0.0f)
      { // Backward
         ret.Y = 1.0f;
      }
      else
      { // Forward
         ret.Y = -1.0f;
      }
   }
   return ret;
}
