#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "style_cyber.h"

struct Ball {
  Vector2 position;
  Vector2 velocity;
  float bouncines;
  float weight;
  float normalForce;
};

int main() {
  const int screenSize = 800;
  const float gravity = 9.81 * 5;
  const int balls = 208;

  Ball ball[balls];
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
  InitWindow(screenSize, screenSize, "Graph Renderer");
  SetTargetFPS(120);
  GuiLoadStyleCyber();

  while (!WindowShouldClose()) {

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
