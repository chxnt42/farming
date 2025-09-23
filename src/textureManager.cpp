#include "textureManager.h"
#include "raylib.h"

#define __WIN32

textureManager::textureManager()
{

}

textureManager::~textureManager()
{

}

void textureManager::init()
{
    #ifdef __WIN32

        

    auto exePath = std::filesystem::current_path();
    auto parent = exePath.parent_path().parent_path().parent_path();


    std::filesystem::path CarrotPath = parent / "assets" / "carrot.png";
    std::filesystem::path DirtPath = parent / "assets" / "dirt.png";
    std::filesystem::path HightlightPath = parent / "assets" / "highlight.png";
    std::filesystem::path UIItem = parent / "assets" / "ui_item.png";

    textureArray[static_cast<int>(TextureType::DIRT_TILE)] = LoadTexture(DirtPath.string().c_str());
    textureArray[static_cast<int>(TextureType::HIGHLIGHT)] = LoadTexture(HightlightPath.string().c_str());
    textureArray[static_cast<int>(TextureType::UI_ITEM)] = LoadTexture(UIItem.string().c_str());
    textureArray[static_cast<int>(TextureType::CARROT_ICON)] = LoadTexture(CarrotPath.string().c_str());
        
    #else
        textureArray[static_cast<int>(TextureType::DIRT_TILE)] = LoadTexture("../assets/dirt.png");
        textureArray[static_cast<int>(TextureType::HIGHLIGHT)] = LoadTexture("../assets/highlight.png");
        textureArray[static_cast<int>(TextureType::UI_ITEM)] = LoadTexture("../assets/ui_item.png");
        textureArray[static_cast<int>(TextureType::CARROT_ICON)] = LoadTexture("../assets/carrot.png");
    #endif
    
}

Texture2D textureManager::getTexture(TextureType type)
{
    return textureArray[static_cast<int>(type)];
}