#include <iostream>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "style_cyber.h"

struct Point {
  Vector2 position;
  Vector2 velocity;
  float bouncines;
};

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  const float gravity = 9.81 * 10;

  Point ball;
  ball.position = {50, 50};
  ball.velocity = {0, 0};
  ball.bouncines = 0.77;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Graph Renderer");
  SetTargetFPS(60);
  GuiLoadStyleCyber();

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    ball.velocity.y += gravity * deltaTime;

    ball.position.x += ball.velocity.x * deltaTime;
    ball.position.y += ball.velocity.y * deltaTime;

    if (ball.position.y >= screenHeight || ball.position.y <= 0) {
      ball.velocity.y = -ball.velocity.y * ball.bouncines;
    }
    if (ball.position.x >= screenWidth || ball.position.x <= 0) {
      ball.velocity.x = -ball.velocity.x * ball.bouncines;
    }

    std::cout << "velocity" << std::endl;
    std::cout << ball.velocity.x << std::endl;
    std::cout << ball.velocity.y << std::endl;

    std::cout << "pos" << std::endl;
    std::cout << ball.position.x << std::endl;
    std::cout << ball.position.y << std::endl;

    DrawCircleV(ball.position, 5, BLUE);

    BeginDrawing();
    ClearBackground(GRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
