#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "style_cyber.h"

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Graph Renderer");
  GuiLoadStyleCyber();

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(GRAY);

    GuiPanel((Rectangle){0, 0, 120, 30}, "gowno");

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
