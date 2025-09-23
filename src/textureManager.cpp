#include "textureManager.h"
#include "raylib.h"
#include <filesystem>

#define __WIN32

textureManager::textureManager()
{

}

textureManager::~textureManager()
{

}


std::string resolvePath(const char *pngName)
{
    auto exePath = std::filesystem::current_path();
    auto parent = exePath.parent_path().parent_path().parent_path();
    std::filesystem::path tempPath = parent / "assets" / pngName;
    return tempPath.string();
}


void textureManager::init()
{
    #ifdef __WIN32

        


    textureArray[static_cast<int>(TextureType::DIRT_TILE)] = LoadTexture(resolvePath("dirt.png").c_str());
    textureArray[static_cast<int>(TextureType::HIGHLIGHT)] = LoadTexture(resolvePath("highlight.png").c_str());
    textureArray[static_cast<int>(TextureType::UI_ITEM)] = LoadTexture(resolvePath("ui_item.png").c_str());
    textureArray[static_cast<int>(TextureType::CARROT_ICON)] = LoadTexture(resolvePath("carrot.png").c_str());
    textureArray[static_cast<int>(TextureType::CARROT_SHEET)] = LoadTexture(resolvePath("carrot_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::SQAURE_CARD_BG)] = LoadTexture(resolvePath("square_card.png").c_str());
     textureArray[static_cast<int>(TextureType::CIRCLE_CARD_ICON)] = LoadTexture(resolvePath("circle_card.png").c_str());
        
    #else
        textureArray[static_cast<int>(TextureType::DIRT_TILE)] = LoadTexture("../assets/dirt.png");
        textureArray[static_cast<int>(TextureType::HIGHLIGHT)] = LoadTexture("../assets/highlight.png");
        textureArray[static_cast<int>(TextureType::UI_ITEM)] = LoadTexture("../assets/ui_item.png");
        textureArray[static_cast<int>(TextureType::CARROT_ICON)] = LoadTexture("../assets/carrot.png");
        textureArray[static_cast<int>(TextureType::CARROT_SHEET)] = LoadTexture("../assets/carrot_sheet.png");
        textureArray[static_cast<int>(TextureType::SQAURE_CARD_BG)] = LoadTexture("../assets/square_card.png");
        textureArray[static_cast<int>(TextureType::CIRCLE_CARD_ICON)] = LoadTexture("../assets/circle_card.png");
    #endif
    
}

Texture2D textureManager::getTexture(TextureType type)
{
    return textureArray[static_cast<int>(type)];
}