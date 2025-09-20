#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "raylib.h"
#pragma once

enum class TextureType 
{
    DIRT_TILE,
    HIGHLIGHT,
    UI_ITEM,
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