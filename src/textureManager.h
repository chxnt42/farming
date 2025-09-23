#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#pragma once



#include "raylib.h"
#include <filesystem>


enum class TextureType 
{
    DIRT_TILE,
    HIGHLIGHT,
    UI_ITEM,
    CARROT_ICON,
    COUNT //make sure count is always last in the enum
};


class textureManager
{
public:
    textureManager();
    ~textureManager();

    Texture2D getTexture(TextureType type);

    void init();

private:
    Texture2D textureArray[static_cast<int>(TextureType::COUNT) + 1];
};

#endif