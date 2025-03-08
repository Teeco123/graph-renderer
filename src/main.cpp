#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "raylib.h"
#include "style_cyber.h"

#include "utils.h"

int main() {
  const int screenHeight = 800;
  const int screenWidth = 1000;
  Vector2 resolution = {800, 800};

  // All raylib settings
  InitWindow(screenWidth, screenHeight, "Graph Renderer");
  SetTargetFPS(120);
  GuiLoadStyleCyber();

  Shader shader = LoadShader(0, TextFormat("src/shaders/test.fragment", 330));

  // Loading points
  const int pointsCount = 202;
  Point point[pointsCount];
  InitRandomPoints(point, pointsCount);

  float radius = 80; // Influence radius

  int pointsLoc = GetShaderLocation(shader, "points");
  int numPointsLoc = GetShaderLocation(shader, "numPoints");
  int radiusLoc = GetShaderLocation(shader, "radius");
  int resolutionLoc = GetShaderLocation(shader, "resolution");

  SetShaderValue(shader, numPointsLoc, &pointsCount, SHADER_UNIFORM_INT);
  SetShaderValue(shader, radiusLoc, &radius, SHADER_UNIFORM_FLOAT);
  SetShaderValue(shader, resolutionLoc, &resolution, SHADER_UNIFORM_VEC2);
  SetShaderValueV(shader, pointsLoc, point, SHADER_UNIFORM_VEC2, pointsCount);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(GRAY);

    BeginShaderMode(shader);
    DrawRectangle(0, 0, 800, 800, WHITE);
    EndShaderMode();

    DrawRectangleLines(0, 0, 800, 800, BLACK);

    for (int i = 0; i < pointsCount; i++) {
      DrawCircleV(point[i].position, 5, WHITE);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
