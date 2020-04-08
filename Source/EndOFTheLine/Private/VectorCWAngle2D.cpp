// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorCWAngle2D.h"
#include "Kismet/KismetMathLibrary.h"

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


float wrap(float val, float min, float max)
{
   float tmp;
   while (val > max)
   {
      tmp = val - fabs(max);
      val = min + tmp;
   }
   while (val < min)
   {
      tmp = val + fabs(min);
      val = max + tmp;
   }
   return val;
}

/*
-5 , -3, 3
5, -3, 3


*/