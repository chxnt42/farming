#include "ui.h"
#include "game.h"
#include "plant.h"
#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include <cstddef>
#include <memory>

void ui::draggableContainer::draw()
{
    auto &manager = Game::instance().m_textureManager;

    Texture2D UiItemTexture = manager->getTexture(TextureType::UI_ITEM);
    DrawTexturePro(UiItemTexture, {0, 0, (float)UiItemTexture.width, (float)UiItemTexture.height},
                   {bounds.x, bounds.y, bounds.width, bounds.height}, {0, 0}, 0, WHITE);

    if (item)
    {
        item->draw();
    }
}

void ui::draggableContainer::onDrag()
{
    auto mousePos = GetMousePosition();
    mousePos.x = mousePos.x - ((item->plant->plantIconTexture.width * item->scale) / 2);
    mousePos.y = mousePos.y - ((item->plant->plantIconTexture.height * item->scale) / 2);

    item->position = mousePos;
}

void ui::draggableContainer::onStartDrag()
{
    item->onDragEnd();
}

void ui::draggableContainer::onStopDrag()
{
    item->onDragEnd();
}

void ui::draggableContainer::onHover()
{
    ui::renderPlantCard(item);
}

void ui::draggableContainer::update()
{
    Vector2 mousePos = GetMousePosition();

    if (CheckCollisionPointRec(mousePos, bounds))
    {
        Game::instance().drawCommandQueue.push([this]() { onHover(); });
    }

    // Start dragging
    if (!isDragging && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, bounds))
    {
        isDragging = true;

        onStartDrag();
    }

    // Continue dragging
    if (isDragging && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        onDrag();
    }

    // Stop dragging
    if (isDragging && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        isDragging = false;

        onStopDrag();
    }
}

ui::baseUiItem::baseUiItem(ui::draggableContainer *_parent, float _scale)
{
    parentContainer = _parent;
    scale = _scale;

    if (_parent)
    {
        position = {_parent->bounds.x + (_parent->bounds.width / 4), _parent->bounds.y + (_parent->bounds.height / 4)};
        int t = 0;
    }
}

void ui::baseUiItem::draw()
{
    DrawTexturePro(plant->plantIconTexture,
                   {0, 0, (float)plant->plantIconTexture.width, (float)plant->plantIconTexture.height},
                   {position.x, position.y, (float)plant->plantIconTexture.width * scale,
                    (float)plant->plantIconTexture.height * scale},
                   {0, 0}, 0.0f, WHITE);
}

void ui::carrotUiItem::onDragEnd()
{
    auto tileGridPos = Game::instance().getHoveredTile(GetMousePosition());

    if (tileGridPos.has_value())
    {
        Tile &tileObj = Game::instance().m_tiles[tileGridPos.value()]; // implement planting logic
        tileObj.plant = std::make_unique<Carrot>();
        position = {parentContainer->bounds.x + (parentContainer->bounds.width / 4),
                    parentContainer->bounds.y + (parentContainer->bounds.height / 4)};
    }
    else
    {
        position = {parentContainer->bounds.x + (parentContainer->bounds.width / 4),
                    parentContainer->bounds.y +
                        (parentContainer->bounds.height / 4)}; // resset back to container position
    }
}

void ui::renderPlantCard(std::unique_ptr<baseUiItem> &UIItem)
{
    // Do not change order as positions are relative

    Texture2D UiCardTexture = Game::instance().m_textureManager->getTexture(TextureType::SQAURE_CARD_BG);
    float cardScale = 1.5f;
    Vector2 cardPosition = { (float)Game::instance().m_screenWidth / Game::instance().cam.zoom - (UiCardTexture.width * 0.75f) * cardScale , 0 };
    DrawTexturePro(UiCardTexture, { 0, 0, (float)UiCardTexture.width, (float)UiCardTexture.height },
        { cardPosition.x, cardPosition.y, (UiCardTexture.width * 0.75f) * cardScale, ((float)UiCardTexture.height) * cardScale }, { 0,0 }, 0, WHITE);

    Texture2D UiCircleTexture = Game::instance().m_textureManager->getTexture(TextureType::CIRCLE_CARD_ICON);
    Vector2 circlePosition = { cardPosition.x + 10, cardPosition.y + 10 };
    DrawTexturePro(UiCircleTexture, { 0, 0, (float)UiCircleTexture.width, (float)UiCircleTexture.height },
        { circlePosition.x, circlePosition.y, ((float)UiCircleTexture.width), ((float)UiCircleTexture.height) }, { 0,0 }, 0, WHITE);

    if (UIItem != nullptr)
    {
        Texture2D UiPlantTexture = UIItem->plant->plantIconTexture;
        float plantScale = 2.0f;
        Vector2 plantPosition = { circlePosition.x + (UiCircleTexture.width - UiPlantTexture.width * plantScale) / 2,
                                  circlePosition.y + (UiCircleTexture.height - UiPlantTexture.height * plantScale) / 2 };
        DrawTexturePro(UiPlantTexture, { 0, 0, (float)UiPlantTexture.width, (float)UiPlantTexture.height },
            { plantPosition.x, plantPosition.y, ((float)UiPlantTexture.width) * plantScale, ((float)UiPlantTexture.height) * plantScale }, { 0,0 }, 0, WHITE);
    }
}

void ui::renderPlantCard(std::unique_ptr<Plant> &plantItem)
{
    // Do not change order as positions are relative

    Texture2D UiCardTexture = Game::instance().m_textureManager->getTexture(TextureType::SQAURE_CARD_BG);
    float cardScale = 1.5f;
    Vector2 cardPosition = { (float)Game::instance().m_screenWidth / Game::instance().cam.zoom - (UiCardTexture.width * 0.75f) * cardScale , 0 };
    DrawTexturePro(UiCardTexture, { 0, 0, (float)UiCardTexture.width, (float)UiCardTexture.height },
        { cardPosition.x, cardPosition.y, (UiCardTexture.width * 0.75f) * cardScale, ((float)UiCardTexture.height) * cardScale }, {0,0}, 0, WHITE);

    Texture2D UiCircleTexture = Game::instance().m_textureManager->getTexture(TextureType::CIRCLE_CARD_ICON);
    Vector2 circlePosition = {cardPosition.x + 10, cardPosition.y + 10};
    DrawTexturePro(UiCircleTexture, { 0, 0, (float)UiCircleTexture.width, (float)UiCircleTexture.height },
        { circlePosition.x, circlePosition.y, ((float)UiCircleTexture.width), ((float)UiCircleTexture.height) }, { 0,0 }, 0, WHITE);

    if(plantItem != nullptr)
    {
        Texture2D UiPlantTexture = plantItem->plantIconTexture;
        float plantScale = 2.0f;
        Vector2 plantPosition = { circlePosition.x + (UiCircleTexture.width - UiPlantTexture.width * plantScale) / 2,
                                  circlePosition.y + (UiCircleTexture.height - UiPlantTexture.height * plantScale) / 2 };
        DrawTexturePro(UiPlantTexture, { 0, 0, (float)UiPlantTexture.width, (float)UiPlantTexture.height },
            { plantPosition.x, plantPosition.y, ((float)UiPlantTexture.width) * plantScale, ((float)UiPlantTexture.height) * plantScale }, { 0,0 }, 0, WHITE);
    }
}