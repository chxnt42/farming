#include "game.h"
#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include <memory>


Game::~Game()
{

}


void Game::init()
{
    m_textureManager = std::make_unique<textureManager>();
    m_textureManager->init();
}



void Game::drawTiles()
{
    for(auto pair : m_tiles)
    {
        int x_grid = pair.first.first;
        int y_grid = pair.first.second;

        DrawTexture(m_textureManager->getTexture(TextureType::DIRT_TILE), x_grid * m_tileSize, y_grid * m_tileSize, WHITE);
    }
}

void Game::draw()
{
    drawTiles();
}