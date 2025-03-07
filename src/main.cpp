#include <algorithm>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "style_cyber.h"

struct Point {
  Vector2 position;
  Vector2 velocity;
  float bouncines;
  float weight;
  float normalForce;
};

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  const float gravity = 9.81 * 5;
  const int balls = 208;

  Point ball[balls];

  float column = 10;
  float row = 10;
  for (int i = 0; i < balls; i++) {
    ball[i].position = {row, column};
    ball[i].velocity = {50, 0};
    ball[i].bouncines = 0.5;
    ball[i].weight = 5;
    ball[i].normalForce = ball[i].weight * gravity;

    row = row + 50;

    if (row > 800) {
      column += 50;
      row = 10;
    }
  }

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Graph Renderer");
  SetTargetFPS(120);
  GuiLoadStyleCyber();

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    for (int i = 0; i < balls; i++) {
      ball[i].velocity.y += gravity * deltaTime;
      ball[i].position.x += ball[i].velocity.x * deltaTime;
      ball[i].position.y += ball[i].velocity.y * deltaTime;

      float kineticFriction = 0.5 * ball[i].normalForce;
      float frictionAcceleration = -kineticFriction / ball[i].weight;

      // Bounce off bottom and top
      if (ball[i].position.y >= screenHeight) {
        ball[i].position.y = screenHeight;
        ball[i].velocity.y = -ball[i].velocity.y * ball[i].bouncines;

        if (ball[i].velocity.x > 0) {
          int tempVelocity = ball[i].velocity.x + frictionAcceleration;
          ball[i].velocity.x = std::max(0, tempVelocity);
        }
        if (ball[i].velocity.x < 0) {
          int tempVelocity = ball[i].velocity.x - frictionAcceleration;
          ball[i].velocity.x = std::min(0, tempVelocity);
        }
      }

      // Bounce off left and right
      if (ball[i].position.x >= screenWidth) {
        ball[i].position.x = screenWidth;
        ball[i].velocity.x = -ball[i].velocity.x * ball[i].bouncines;
      } else if (ball[i].position.x <= 0) {
        ball[i].position.x = 0;
        ball[i].velocity.x = -ball[i].velocity.x * ball[i].bouncines;
      }
    }

    BeginDrawing();
    ClearBackground(GRAY);

    for (int i = 0; i < balls; i++) {
      DrawCircleV(ball[i].position, 5, BLUE);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
