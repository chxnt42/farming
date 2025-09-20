
#include <functional>
#include <iostream>
#include <utility>
#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include "utils.h"
#include "game.h"
#include "ui.h"





int main()
{


    InitWindow(Game::instance().m_screenWidth, Game::instance().m_screenHeight, "farming");
    SetTargetFPS(60);

    Game::instance().init();
    Game::instance().m_tiles.insert(std::make_pair(std::make_pair(6, 6), Tile()));

    Color bg_colour = {51,60,58,255};

    ui::draggableContainer test1;
    test1.bounds =  {0,0,60,60};


    while (!WindowShouldClose())
    {
   

        Game::instance().update();

  
        test1.update();
        

        BeginDrawing();
            BeginMode2D(Game::instance().cam);
                ClearBackground(bg_colour);

                Game::instance().draw();


            EndMode2D();

            test1.draw();
        EndDrawing();

    }

}
