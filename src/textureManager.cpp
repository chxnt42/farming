#include "textureManager.h"
#include "raylib.h"

textureManager::textureManager()
{

}

textureManager::~textureManager()
{

}

void textureManager::init()
{
    textureArray[static_cast<int>(TextureType::DIRT_TILE)] = LoadTexture("./assets/dirt.png");
    textureArray[static_cast<int>(TextureType::HIGHLIGHT)] = LoadTexture("./assets/highlight.png");
    textureArray[static_cast<int>(TextureType::UI_ITEM)] = LoadTexture("./assets/ui_item.png");
     textureArray[static_cast<int>(TextureType::CARROT_ICON)] = LoadTexture("./assets/carrot.png");
}

Texture2D textureManager::getTexture(TextureType type)
{
    return textureArray[static_cast<int>(type)];
}