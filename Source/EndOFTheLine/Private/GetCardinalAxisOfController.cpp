// Fill out your copyright notice in the Description page of Project Settings.


#include "GetCardinalAxisOfController.h"

FVector2D UGetCardinalAxisOfController::GetCardinalAxisOfController(FVector2D vector)
{
   FVector2D ret = {.0f, .0f};
   if (fabsf(vector.X) > fabsf(vector.Y)) // This means they are aiming either to the left or to the right
   {
      if (vector.X >= 0)
      { // Right
         ret.X = 1;
      }
      else
      { // Left
         ret.X = -1;
      }
   }
   else // This means they are aiming either forward or backwards
   {
      if (vector.Y >= 0)
      { // Forward
         ret.Y = 1;
      }
      else
      { // Backward
         ret.Y = -1;
      }
   }
   return ret;
}
