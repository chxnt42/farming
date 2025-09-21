#include "ui.h"
#include "game.h"
#include "plant.h"
#include "raylib.h"
#include "textureManager.h"
#include "tile.h"
#include <memory>

void ui::draggableContainer::draw()
{
    auto &manager = Game::instance().m_textureManager;

    Texture2D UiItemTexture = manager->getTexture(TextureType::UI_ITEM);
    DrawTexturePro(UiItemTexture, {0, 0, (float)UiItemTexture.width, (float)UiItemTexture.height},
                   {bounds.x, bounds.y, bounds.width, bounds.height}, {0,0}, 0, WHITE);

    if (item)
    {
        item->draw();
    }
}

void ui::draggableContainer::onDrag()
{
    auto mousePos = GetMousePosition();
    mousePos.x = mousePos.x - ((item->itemTexture.width * item->scale) / 2);
    mousePos.y = mousePos.y - ((item->itemTexture.height * item->scale) / 2);

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

void ui::draggableContainer::update()
{
    Vector2 mousePos = GetMousePosition();

    if (CheckCollisionPointRec(mousePos, bounds))
    {
        onHover();
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

ui::baseUiItem::baseUiItem(ui::draggableContainer *_parent, Texture2D _itemTexture,float _scale)
{
    parentContainer = _parent;
    itemTexture = _itemTexture;
    scale = _scale;


    if (_parent)
    {
        position = {_parent->bounds.x + (_parent->bounds.width / 4), _parent->bounds.y + (_parent->bounds.height / 4)};
        int t = 0;
    }
}

void ui::baseUiItem::draw()
{
    DrawTexturePro(
        itemTexture, {0, 0, (float)itemTexture.width, (float)itemTexture.height},      
        {position.x, position.y, (float)itemTexture.width * scale, (float)itemTexture.height * scale}, 
        {0, 0},                                                                      
        0.0f,                                                                       
        WHITE);
}



void ui::carrotUiItem::onDragEnd()
{
    auto tileGridPos = Game::instance().getHoveredTile(GetMousePosition());

    if(tileGridPos.has_value())
    {
        Tile& tileObj = Game::instance().m_tiles[tileGridPos.value()]; //implement planting logic
        tileObj.plant = std::make_unique<Carrot>();
    }
    else
    {
        position = {parentContainer->bounds.x + (parentContainer->bounds.width / 4), parentContainer->bounds.y + (parentContainer->bounds.height / 4)}; //resset back to container position
    }

}   