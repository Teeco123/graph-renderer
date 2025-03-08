#include "raylib.h"
#include "types.h"

float SmoothingKernel(float radius, float dst);
float Distance2Vectors(Vector2 A, Vector2 B);
float CalculateDensity(Vector2 samplePoint, Point point[], float radius);
void InitRandomPoints(Point poinr[], int count);
