#include <algorithm>
#include <iostream>
#include <ostream>

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

  Point ball;
  ball.position = {50, 50};
  ball.velocity = {100, 0};
  ball.bouncines = 0.5;
  ball.weight = 5;
  ball.normalForce = ball.weight * gravity;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Graph Renderer");
  SetTargetFPS(120);
  GuiLoadStyleCyber();

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    ball.velocity.y += gravity * deltaTime;

    ball.position.x += ball.velocity.x * deltaTime;
    ball.position.y += ball.velocity.y * deltaTime;

    float kineticFriction = 0.5 * ball.normalForce;
    float frictionAcceleration = -kineticFriction / ball.weight;

    // Bounce off bottom and top
    if (ball.position.y >= screenHeight) {
      ball.position.y = screenHeight;
      ball.velocity.y = -ball.velocity.y * ball.bouncines;

      if (ball.velocity.x > 0) {
        int tempVelocity = ball.velocity.x + frictionAcceleration;
        ball.velocity.x = std::max(0, tempVelocity);
      }
      if (ball.velocity.x < 0) {
        int tempVelocity = ball.velocity.x - frictionAcceleration;
        ball.velocity.x = std::min(0, tempVelocity);
      }
    }

    // Bounce off left and right
    if (ball.position.x >= screenWidth) {
      ball.position.x = screenWidth;
      ball.velocity.x = -ball.velocity.x * ball.bouncines;
    } else if (ball.position.x <= 0) {
      ball.position.x = 0;
      ball.velocity.x = -ball.velocity.x * ball.bouncines;
    }

    std::cout << "Velocity x:" << ball.velocity.x << std::endl;
    std::cout << "Velocity y:" << ball.velocity.y << std::endl;
    std::cout << std::endl;

    std::cout << "Position x:" << ball.position.x << std::endl;
    std::cout << "Position y:" << ball.position.y << std::endl;
    std::cout << std::endl;

    DrawCircleV(ball.position, 5, BLUE);

    BeginDrawing();
    ClearBackground(GRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
