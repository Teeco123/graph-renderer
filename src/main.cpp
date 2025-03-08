#include "raylib.h"
#include <iostream>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "style_cyber.h"
#include "utils.h"

int main() {
  const int screenHeight = 810;
  const int screenWidth = 1000;
  const float gravity = 9.81 * 5;
  const int balls = 208;

  Ball ball[balls];
  float column = 10;
  float row = 10;

  for (int i = 0; i < balls; i++) {
    float randColumn = rand() % 800;
    float randRow = rand() % 800;
    ball[i].position = {randRow, randColumn};
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

  Vector2 vector = {300, 300};
  float radius = 100;

  float density = CalculateDensity(vector, ball, radius);

  std::cout << density << std::endl;

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(GRAY);

    DrawRectangleLines(0, 0, 800, 800, BLACK);

    DrawCircleV(vector, radius, RED);

    for (int i = 0; i < balls; i++) {
      DrawCircleV(ball[i].position, 5, BLUE);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
