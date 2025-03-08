#include "raylib.h"
#include "types.h"
#include <cmath>

inline float SmoothingKernel(float radius, float dst) {
  float squared = radius * radius - dst * dst;
  float value = (0 < squared) ? squared : 0;

  return value * value * value;
}

inline float Distance2Vectors(Vector2 A, Vector2 B) {
  return std::sqrt(std::pow(B.x - A.x, 2) + std::pow(B.y - A.y, 2));
}

inline float CalculateDensity(Vector2 samplePoint, Ball ball[], float radius) {
  float density = 0;
  const float mass = 1;

  for (int i = 0; i < 200; i++) {
    float dst = Distance2Vectors(samplePoint, ball[i].position);
    // TODO: SmoothingKernel neds fix
    float influence = SmoothingKernel(radius, dst);
    density += mass * influence;
  }

  return density;
}
