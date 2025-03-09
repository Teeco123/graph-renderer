#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "raylib.h"
#include "style_cyber.h"

#include "utils.h"

int main() {
  //------------------------------------------------------------------------------------
  // Resolution settings
  const int screenHeight = 800;
  const int screenWidth = 1200;
  Vector2 resolution = {800, 800};

  //------------------------------------------------------------------------------------
  // Settings variables
  int pointsCount = 202;
  float pointsCountFloat = 202;
  float radius = 80; // Influence radius
  bool displayPoints = true;
  bool displaySPH = true;

  //------------------------------------------------------------------------------------
  // Raylib settings
  InitWindow(screenWidth, screenHeight, "Water Simulation");
  SetTargetFPS(120);
  GuiLoadStyleCyber();

  //------------------------------------------------------------------------------------
  // Loading points
  Point point[pointsCount];
  InitRandomPoints(point, pointsCount);

  //------------------------------------------------------------------------------------
  // Setting up shader
  Shader shader = LoadShader(0, TextFormat("src/shaders/test.fragment", 330));
  int pointsLoc = GetShaderLocation(shader, "points");
  int numPointsLoc = GetShaderLocation(shader, "numPoints");
  int radiusLoc = GetShaderLocation(shader, "radius");
  int resolutionLoc = GetShaderLocation(shader, "resolution");

  while (!WindowShouldClose()) { // Game loop

    //------------------------------------------------------------------------------------
    // Passing values to shader
    SetShaderValue(shader, numPointsLoc, &pointsCount, SHADER_UNIFORM_INT);
    SetShaderValue(shader, radiusLoc, &radius, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, resolutionLoc, &resolution, SHADER_UNIFORM_VEC2);
    SetShaderValueV(shader, pointsLoc, point, SHADER_UNIFORM_VEC2, pointsCount);

    BeginDrawing(); // Begin draw

    //------------------------------------------------------------------------------------
    // Main simulation window

    if (displaySPH) {
      BeginShaderMode(shader);
      DrawRectangle(0, 0, 800, 800, WHITE);
      EndShaderMode();
    } else {
      DrawRectangle(0, 0, 800, 800, BLACK);
    }

    if (displayPoints) {
      for (int i = 0; i < pointsCount; i++) {
        DrawCircleV(point[i].position, 5, WHITE);
      }
    }

    DrawRectangleLines(0, 0, 800, 800, BLACK);

    //------------------------------------------------------------------------------------
    // Settings window
    GuiWindowBox((Rectangle){800, 0, 400, 800}, TextFormat("Settings"));

    GuiSlider((Rectangle){802, 25, 250, 20}, NULL,
              TextFormat("Radius: %0.2f", radius), &radius, 0, 300);

    pointsCount = static_cast<int>(pointsCountFloat);
    GuiSlider((Rectangle){802, 45, 250, 20}, NULL,
              TextFormat("Points count: %0.2f", pointsCountFloat),
              &pointsCountFloat, 0, 202);

    GuiCheckBox((Rectangle){802, 65, 20, 20}, TextFormat("Toggle points"),
                &displayPoints);

    GuiCheckBox((Rectangle){802, 85, 20, 20}, TextFormat("Toggle SPH"),
                &displaySPH);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
