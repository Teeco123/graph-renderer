#include <raylib.h>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Graph Renderer");

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(GRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
