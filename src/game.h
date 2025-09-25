#ifndef GAME_H
#define GAME_H
#include <memory>
#include <queue>
#include <utility>
#include <vector>
#include <memory.h>
#include <optional>
#include <unordered_map>
#include <functional>
#pragma once


#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include "utils.h"


namespace ui {
    class draggableContainer; // Forward declaration only
}





class Game
{
  public:
    std::unique_ptr<textureManager> m_textureManager;
    std::unordered_map<std::pair<int, int>, Tile, pairhash> m_tiles;
    Camera2D cam;

    int money = 100;

    int m_screenWidth = 1920;
    int m_screenHeight = 1080;
    int m_tileSize = 16;
    int m_tileGridOffset = (m_screenHeight / 4) * 16;
    std::queue<std::function<void()>> drawCommandQueue;

    std::vector<std::shared_ptr<ui::draggableContainer>> Inventory;


    Font primaryFont;

   

    std::optional<std::pair<int, int>> currentHoveredTile;

    static Game &instance()
    {
        static Game *instance = new Game();
        return *instance;
    }

    void draw();
    void drawUI();

    
    void update();

    void init();
    void addTile();
    std::optional<std::pair<int, int>> getHoveredTile(Vector2 mousePos);

    ~Game();

  private:
    void drawTiles();
};

#endif