#ifndef GAME_H
#define GAME_H
#include "textureManager.h"
#include <memory>
#pragma once

#include <memory.h>
#include <unordered_map>


#include "utils.h"
#include "tile.h"






class Game
{
  public:
    std::unique_ptr<textureManager> m_textureManager;
    std::unordered_map<std::pair<int, int>, Tile, pairhash> m_tiles;

    int m_screenWidth = 400;
	int m_screenHeight = 400;
    int m_tileSize = 16;
    int m_tileGridOffset = (m_screenHeight / 4) * 16;

    static Game &instance()
    {
        static Game *instance = new Game();
        return *instance;
    }

    void draw();
    void init();
    void addTile();

    ~Game();

  private:
    
    void drawTiles();
};

#endif