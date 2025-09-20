#include "ui.h"
#include "game.h"
#include "raylib.h"
#include "textureManager.h"

void ui::draggableContainer::draw()
{
    auto &manager = Game::instance().m_textureManager;

    Texture2D UiItemTexture = manager->getTexture(TextureType::UI_ITEM);
    DrawTexturePro(UiItemTexture, {0, 0, (float)UiItemTexture.width, (float)UiItemTexture.height},
                   {0, 0, bounds.width, bounds.height}, {bounds.x, bounds.y}, 0, WHITE);
}

void ui::draggableContainer::onDrag()
{
    std::cout << " dragging" << std::endl;
}

void ui::draggableContainer::onStartDrag()
{
    std::cout << "started drag" << std::endl;
}

void ui::draggableContainer::onStopDrag()
{
    std::cout << "stopped drag" << std::endl;
}

void ui::draggableContainer::update()
{
    Vector2 mousePos = GetMousePosition();


    if(CheckCollisionPointRec(mousePos, bounds))
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
