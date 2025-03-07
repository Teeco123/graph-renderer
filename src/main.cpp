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

struct Box {
  int row, col;
  int x, y;
  int size;
  Color color;
  int density;
};

int main() {
  const int screenSize = 800;
  const int boxSegments = 50;
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

  Box grid[boxSegments][boxSegments];
  int boxSize = screenSize / boxSegments;
  for (int row = 0; row < boxSegments; row++) {
    for (int col = 0; col < boxSegments; col++) {
      for (int i = 0; i < boxSegments; i++) {
        grid[row][col].row = row;
        grid[row][col].col = col;
        grid[row][col].x = col * boxSize;
        grid[row][col].y = row * boxSize;
        grid[row][col].size = boxSize;
        grid[row][col].color = RED;
        grid[row][col].density = 0;
      }
    }
  }

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenSize, screenSize, "Graph Renderer");
  SetTargetFPS(120);
  GuiLoadStyleCyber();

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    BeginDrawing();
    ClearBackground(GRAY);

    for (int row = 0; row < boxSegments; row++) {
      for (int col = 0; col < boxSegments; col++) {
        Box b = grid[row][col];

        DrawRectangle(b.x, b.y, b.size, b.size, b.color);
        DrawRectangleLines(b.x, b.y, b.size, b.size, BLACK);
      }
    }

    for (int i = 0; i < balls; i++) {
      DrawCircleV(ball[i].position, 5, BLUE);
    }

    for (int i = 0; i < balls; i++) {
      for (int row = 0; row < boxSegments; row++) {
        for (int col = 0; col < boxSegments; col++) {
          Box b = grid[row][col];
          Rectangle box = {(float)b.x, (float)b.y, (float)b.size,
                           (float)b.size};

          if (CheckCollisionPointRec(ball[i].position, box)) {
            grid[row][col].color = PINK;
          }
        }
      }
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
