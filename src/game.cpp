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

    cam.offset = {0,0};
    cam.zoom = 2.0f;
    cam.rotation = 0.0f;
    cam.target = {0,0};
}

void Game::drawTiles()
{
    for (const auto& pair : m_tiles)
    {
        int x_grid = pair.first.first;
        int y_grid = pair.first.second;

        DrawTexture(m_textureManager->getTexture(TextureType::DIRT_TILE), x_grid * m_tileSize, y_grid * m_tileSize,
                    WHITE);
    }
}

void Game::draw()
{
    drawTiles();

    if(currentHoveredTile.has_value())
    {
        DrawTexture(m_textureManager->getTexture(TextureType::HIGHLIGHT), currentHoveredTile.value().first * m_tileSize, currentHoveredTile.value().second * m_tileSize,WHITE);
    }
        
}

std::optional<std::pair<int, int>> Game::getHoveredTile(Vector2 mousePos)
{

    Vector2 relativeMousePos = GetScreenToWorld2D(mousePos,cam);
    
    int grid_x = relativeMousePos.x / m_tileSize;
    int grid_y = relativeMousePos.y / m_tileSize;


    if (m_tiles.contains({grid_x,grid_y})) // found a tile at mousePos
    {
        return std::make_pair(grid_x, grid_y);
    }
    else
    {
        return std::nullopt;
    }
}


void Game::update()
{
    currentHoveredTile = getHoveredTile(GetMousePosition());
}

