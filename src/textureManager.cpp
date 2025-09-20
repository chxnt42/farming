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
}

Texture2D textureManager::getTexture(TextureType type)
{
    return textureArray[static_cast<int>(type)];
}