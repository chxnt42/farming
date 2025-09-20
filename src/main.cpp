
#include <functional>
#include <iostream>
#include <utility>
#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include "utils.h"
#include "game.h"




int main(int, char **)
{
    Game game;

    InitWindow(game.m_screenWidth, game.m_screenHeight, "farming");
    SetTargetFPS(60);

    game.init();
    game.m_tiles.insert(std::make_pair(std::make_pair(0, 0), Tile()));


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        game.draw();
        

        EndDrawing();

    }

}
