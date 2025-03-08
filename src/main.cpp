#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "raylib.h"
#include "style_cyber.h"

#include "utils.h"

int main() {
  const int screenHeight = 810;
  const int screenWidth = 1000;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Graph Renderer");
  SetTargetFPS(120);
  GuiLoadStyleCyber();

  const int ballsCount = 208;
  Ball ball[ballsCount];

  InitRandomPoints(ball, ballsCount);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(GRAY);

    DrawRectangleLines(0, 0, 800, 800, BLACK);

    for (int i = 0; i < ballsCount; i++) {
      DrawCircleV(ball[i].position, 5, BLUE);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
