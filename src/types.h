#include "raylib.h"

struct Ball {
  Vector2 position;
  Vector2 velocity;
  float bouncines;
  float weight;
  float normalForce;
};
