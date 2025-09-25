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
    CARROT_SHEET,
    SWEETPEA_ICON,
    SWEETPEA_SHEET,
    SQUASH_ICON,
    SQUASH_SHEET,
    LETTUCE_ICON,
    LETTUCE_SHEET,
    ORANGE_ICON,
    ORANGE_SHEET,
    SPINACH_ICON,
    SPINACH_SHEET,
    BLUEBERRY_ICON,
    BLUEBERRY_SHEET,
    PUMPKIN_ICON,
    PUMPKIN_SHEET,
    CABBAGE_ICON,
    CABBAGE_SHEET,
    PARSNIP_ICON,
    PARSNIP_SHEET,
    BROCCOLI_ICON,
    BROCCOLI_SHEET,
    BUTTERCUP_ICON,
    BUTTERCUP_SHEET,


    SQAURE_CARD_BG,
    CIRCLE_CARD_ICON,
    COUNT //make sure count is always last in the enum
};


std::string resolvePath(const char* pngName);

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