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
    textureArray[static_cast<int>(TextureType::SWEETPEA_ICON)] = LoadTexture(resolvePath("sweetpea.png").c_str());
    textureArray[static_cast<int>(TextureType::SWEETPEA_SHEET)] = LoadTexture(resolvePath("sweetpea_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::SQUASH_ICON)] = LoadTexture(resolvePath("squash.png").c_str());
    textureArray[static_cast<int>(TextureType::SQUASH_SHEET)] = LoadTexture(resolvePath("squash_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::LETTUCE_ICON)] = LoadTexture(resolvePath("lettuce.png").c_str());
    textureArray[static_cast<int>(TextureType::LETTUCE_SHEET)] = LoadTexture(resolvePath("lettuce_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::ORANGE_ICON)] = LoadTexture(resolvePath("orange.png").c_str());
    textureArray[static_cast<int>(TextureType::ORANGE_SHEET)] = LoadTexture(resolvePath("orange_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::SPINACH_ICON)] = LoadTexture(resolvePath("spinach.png").c_str());
    textureArray[static_cast<int>(TextureType::SPINACH_SHEET)] = LoadTexture(resolvePath("spinach_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::BLUEBERRY_ICON)] = LoadTexture(resolvePath("blueberry.png").c_str());
    textureArray[static_cast<int>(TextureType::BLUEBERRY_SHEET)] = LoadTexture(resolvePath("blueberry_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::PUMPKIN_ICON)] = LoadTexture(resolvePath("pumpkin.png").c_str());
    textureArray[static_cast<int>(TextureType::PUMPKIN_SHEET)] = LoadTexture(resolvePath("pumpkin_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::CABBAGE_ICON)] = LoadTexture(resolvePath("cabbage.png").c_str());
    textureArray[static_cast<int>(TextureType::CABBAGE_SHEET)] = LoadTexture(resolvePath("cabbage_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::PARSNIP_ICON)] = LoadTexture(resolvePath("parsnip.png").c_str());
    textureArray[static_cast<int>(TextureType::PARSNIP_SHEET)] = LoadTexture(resolvePath("parsnip_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::BROCCOLI_ICON)] = LoadTexture(resolvePath("broccoli.png").c_str());
    textureArray[static_cast<int>(TextureType::BROCCOLI_SHEET)] = LoadTexture(resolvePath("broccoli_sheet.png").c_str());
    textureArray[static_cast<int>(TextureType::BUTTERCUP_ICON)] = LoadTexture(resolvePath("buttercup.png").c_str());
    textureArray[static_cast<int>(TextureType::BUTTERCUP_SHEET)] = LoadTexture(resolvePath("buttercup_sheet.png").c_str());

    textureArray[static_cast<int>(TextureType::SQAURE_CARD_BG)] = LoadTexture(resolvePath("square_card.png").c_str());
    textureArray[static_cast<int>(TextureType::CIRCLE_CARD_ICON)] = LoadTexture(resolvePath("circle_card.png").c_str());
        
    #else
        textureArray[static_cast<int>(TextureType::DIRT_TILE)] = LoadTexture("../assets/dirt.png");
        textureArray[static_cast<int>(TextureType::HIGHLIGHT)] = LoadTexture("../assets/highlight.png");
        textureArray[static_cast<int>(TextureType::UI_ITEM)] = LoadTexture("../assets/ui_item.png");

        textureArray[static_cast<int>(TextureType::CARROT_ICON)] = LoadTexture("../assets/carrot.png");
        textureArray[static_cast<int>(TextureType::CARROT_SHEET)] = LoadTexture("../assets/carrot_sheet.png");
        textureArray[static_cast<int>(TextureType::SWEETPEA_ICON)] = LoadTexture("../assets/sweetpea.png");
        textureArray[static_cast<int>(TextureType::SWEETPEA_SHEET)] = LoadTexture("../assets/sweetpea_sheet.png");
        textureArray[static_cast<int>(TextureType::SQUASH_ICON)] = LoadTexture("../assets/squash.png");
        textureArray[static_cast<int>(TextureType::SQUASH_SHEET)] = LoadTexture("../assets/squash_sheet.png");
        textureArray[static_cast<int>(TextureType::LETTUCE_ICON)] = LoadTexture("../assets/lettuce.png");
        textureArray[static_cast<int>(TextureType::LETTUCE_SHEET)] = LoadTexture("../assets/lettuce_sheet.png");
        textureArray[static_cast<int>(TextureType::ORANGE_ICON)] = LoadTexture("../assets/orange.png");
        textureArray[static_cast<int>(TextureType::ORANGE_SHEET)] = LoadTexture("../assets/orange_sheet.png");
        textureArray[static_cast<int>(TextureType::SPINACH_ICON)] = LoadTexture("../assets/spinach.png");
        textureArray[static_cast<int>(TextureType::SPINACH_SHEET)] = LoadTexture("../assets/spinach_sheet.png");
        textureArray[static_cast<int>(TextureType::BLUEBERRY_ICON)] = LoadTexture("../assets/blueberry.png");
        textureArray[static_cast<int>(TextureType::BLUEBERRY_SHEET)] = LoadTexture("../assets/blueberry_sheet.png");
        textureArray[static_cast<int>(TextureType::PUMPKIN_ICON)] = LoadTexture("../assets/pumpkin.png");
        textureArray[static_cast<int>(TextureType::PUMPKIN_SHEET)] = LoadTexture("../assets/pumpkin_sheet.png");
        textureArray[static_cast<int>(TextureType::CABBAGE_ICON)] = LoadTexture("../assets/cabbage.png");
        textureArray[static_cast<int>(TextureType::CABBAGE_SHEET)] = LoadTexture("../assets/cabbage_sheet.png");
        textureArray[static_cast<int>(TextureType::PARSNIP_ICON)] = LoadTexture("../assets/parsnip.png");
        textureArray[static_cast<int>(TextureType::PARSNIP_SHEET)] = LoadTexture("../assets/parsnip_sheet.png");
        textureArray[static_cast<int>(TextureType::BROCCOLI_ICON)] = LoadTexture("../assets/broccoli.png");
        textureArray[static_cast<int>(TextureType::BROCCOLI_SHEET)] = LoadTexture("../assets/broccoli_sheet.png");
        textureArray[static_cast<int>(TextureType::BUTTERCUP_ICON)] = LoadTexture("../assets/buttercup.png");
        textureArray[static_cast<int>(TextureType::BUTTERCUP_SHEET)] = LoadTexture("../assets/buttercup_sheet.png");

        textureArray[static_cast<int>(TextureType::SQAURE_CARD_BG)] = LoadTexture("../assets/square_card.png");
        textureArray[static_cast<int>(TextureType::CIRCLE_CARD_ICON)] = LoadTexture("../assets/circle_card.png");
    #endif
    
}

Texture2D textureManager::getTexture(TextureType type)
{
    return textureArray[static_cast<int>(type)];
}