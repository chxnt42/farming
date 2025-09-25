#include "game.h"
#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include <memory>

#include "ui.h"

#define __WIN32

Game::~Game()
{
}

void Game::init()
{
    #ifdef __WIN32
    primaryFont = LoadFont(resolvePath("fonts/v5loxicar.ttf").c_str());
    #else
    primaryFont = LoadFont("../assets/fonts/v5loxicar.ttf");
    #endif

    m_textureManager = std::make_unique<textureManager>();
    m_textureManager->init();

    cam.offset = {0, 0};
    cam.zoom = 2.0f;
    cam.rotation = 0.0f;
    cam.target = {0, 0};
}

void Game::drawTiles()
{
    for (auto &pair : m_tiles)
    {
        pair.second.draw(pair.first);
    }
}

void Game::draw()
{
    drawTiles();

    while (!drawCommandQueue.empty())
    {
        drawCommandQueue.front()();
        drawCommandQueue.pop();
    }

    if (currentHoveredTile.has_value())
    {
        DrawTexture(m_textureManager->getTexture(TextureType::HIGHLIGHT), currentHoveredTile.value().first * m_tileSize,
                    currentHoveredTile.value().second * m_tileSize, WHITE);

        ui::renderPlantCard(m_tiles[currentHoveredTile.value()].plant);
    }

    ui::drawMoney();
}

std::optional<std::pair<int, int>> Game::getHoveredTile(Vector2 mousePos)
{

    Vector2 relativeMousePos = GetScreenToWorld2D(mousePos, cam);

    int grid_x = relativeMousePos.x / m_tileSize;
    int grid_y = relativeMousePos.y / m_tileSize;

    if (m_tiles.contains({grid_x, grid_y})) // found a tile at mousePos
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

    for (auto &pair : m_tiles)
    {

        pair.second.update();
    }
}
