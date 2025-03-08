#include "utils.h"
#include "raylib.h"
#include <cmath>

float SmoothingKernel(float radius, float dst) {
  float volume = M_PI * std::pow(radius, 8) / 4;
  float squared = radius * radius - dst * dst;
  float value = (0 < squared) ? squared : 0;

  return value * value * value / volume;
}

float Distance2Vectors(Vector2 A, Vector2 B) {
  return std::sqrt(std::pow(B.x - A.x, 2) + std::pow(B.y - A.y, 2));
}

float CalculateDensity(Vector2 samplePoint, Ball ball[], float radius) {
  float density = 0;
  const float mass = 1;

  for (int i = 0; i < 200; i++) {
    float dst = Distance2Vectors(samplePoint, ball[i].position);
    float influence = SmoothingKernel(radius, dst);
    density += mass * influence;
  }

  return density;
}
