// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorCWAngle2D.h"
#include "Kismet/KismetMathLibrary.h"

float wrap(float val, float min, float max) // -1.5, ,-3, 3
{
   max -= min; //6
   val -= min; // 1.5
   modff(val, &max); // 1.5
   val += min; // - 3

   return val;
}

float UVectorCWAngle2D::VectorCWAngle2D(FVector a, FVector b)
{
   FVector2D vecA;
   vecA.X = a.X; vecA.Y = a.Y;
   vecA.Normalize();

   FVector2D vecB;
   vecB.X = b.X; vecB.Y = b.Y;
   vecB.Normalize();

   float dotProduct = ( vecA.X * vecB.X ) + ( vecA.Y * vecB.Y );
   float determinant = ( vecA.Y * vecB.X ) - ( vecA.X * vecB.Y );

   return atan2f(determinant, dotProduct);
}

float UVectorCWAngle2D::SwitchTargetAngleScore(float angle)
{

   if (angle < 0)
   {
      angle += PI * 2;
   }
   return angle;
}

float UVectorCWAngle2D::AimRightGunScore(FVector a, FVector b)
{
   float ret = VectorCWAngle2D(a, b);
   ret = wrap(ret + ( PI / 2 ), -PI, PI);
   ret = fabsf(ret);
   return ret;
}

/*
*/