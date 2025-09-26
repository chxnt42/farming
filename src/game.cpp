#include "game.h"
#include "plant.h"
#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include <cstddef>
#include <memory>

#include "ui.h" // Now we can include it here

// #define __WIN32

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

    for (int i = 0; i < 10; i++)
    {
        Inventory.push_back(
            std::make_shared<ui::draggableContainer>(Rectangle{(float)700 + (i * 60), 1080 - 60, 60, 60}));
    }
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
        try
        {
            auto &command = drawCommandQueue.front();
            if (command)
            {
                std::cout << "Executing draw command..." << std::endl;
                command();
                std::cout << "Draw command completed." << std::endl;
            }
            else
            {
                std::cout << "Null command found in queue!" << std::endl;
            }
            drawCommandQueue.pop();
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception in draw command: " << e.what() << std::endl;
            drawCommandQueue.pop(); // Remove the problematic command
        }
        catch (...)
        {
            std::cout << "Unknown exception in draw command!" << std::endl;
            drawCommandQueue.pop();
        }
    }

    if (currentHoveredTile.has_value())
    {
        DrawTexture(m_textureManager->getTexture(TextureType::HIGHLIGHT), currentHoveredTile.value().first * m_tileSize,
                    currentHoveredTile.value().second * m_tileSize, WHITE);

        ui::renderPlantCard(m_tiles[currentHoveredTile.value()].plant);
    }

    ui::drawMoney();
}

void Game::drawUI()
{
    for (auto &inventoryButton : Inventory)
    {
        inventoryButton->draw();
    }
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

    for (int i = 0; i < 10; i++)
    {
        Inventory[i]->update();
    }

    if (currentHoveredTile.has_value() && IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        auto gridpos = currentHoveredTile.value();
        Tile &tile = m_tiles[gridpos];

        // This now returns a copy, not moving the original
        std::unique_ptr<Plant> plantCopy = tile.harvest();

        if (plantCopy != nullptr)
        {
            for (int i = 0; i < 10; i++)
            {
                if (Inventory[i]->item == nullptr)
                {
                    auto baseUiItem = std::make_unique<ui::baseUiItem>(Inventory[i].get(), 2.0f);
                    Inventory[i]->item = std::move(baseUiItem);
                    Inventory[i]->item->plant = std::move(plantCopy);
                    break; // Important: break after placing the copy
                }
            }
        }
    }
}
