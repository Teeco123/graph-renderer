#include "raylib.h"
#include "types.h"

float SmoothingKernel(float radius, float dst);
float Distance2Vectors(Vector2 A, Vector2 B);
float CalculateDensity(Vector2 samplePoint, Ball ball[], float radius);
void InitRandomPoints(Ball ball[], int count);
