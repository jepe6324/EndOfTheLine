// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorCWAngle2D.h"
#include "Kismet/KismetMathLibrary.h"

float wrap(float val, float min, float max)
{
   max -= min;
   val -= min;
   modff(val, &max);
   val += min;

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

float UVectorCWAngle2D::VectorCWAngle2D(FVector2D a, FVector b)
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

float UVectorCWAngle2D::AimRightGunScore(FVector controller, FVector enemy, FVector2D controllerCardinal)
{
   float var = VectorCWAngle2D(controllerCardinal, enemy);
   var = wrap(var + (PI / 2), -PI, PI);
   var = fabsf(var);
   if (var > PI / 4)
   {
      return 10.0f; // This means that the enemy was at a non valid angle in comparison to the controller input
   }
   return fabsf(wrap(VectorCWAngle2D(controller, enemy) + (PI / 2), -PI, PI));
}
