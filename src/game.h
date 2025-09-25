#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "textureManager.h"
#include <memory>
#include <queue>
#include <utility>
#pragma once

#include <memory.h>
#include <optional>
#include <unordered_map>

#include "tile.h"
#include "utils.h"
#include <functional>


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


    Font primaryFont;

   

    std::optional<std::pair<int, int>> currentHoveredTile;

    static Game &instance()
    {
        static Game *instance = new Game();
        return *instance;
    }

    void draw();
    void update();

    void init();
    void addTile();
    std::optional<std::pair<int, int>> getHoveredTile(Vector2 mousePos);

    ~Game();

  private:
    void drawTiles();
};

#endif