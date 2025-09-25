#include "plant.h"
#include "game.h"
#include "raylib.h"
#include "textureManager.h"
#include <iostream>




Carrot::Carrot()
{
    plantName = "Carrot";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::CARROT_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::CARROT_SHEET);
    growthSpeed = 2.15;
}


void Plant::draw(const std::pair<int,int>& gridPos)
{
    DrawTexturePro(growthTextureSheet,{(float)currentGrowthStage * 16,0,16,16},{(float)gridPos.first * 16,(float)gridPos.second*16,16,16},{0,0},0,WHITE);
}

void Plant::update()
{
    float currentTime = GetTime();

    if(currentTime - lastUpdateTime >= growthSpeed) 
    {
        if(currentGrowthStage + 1 <= 4)
        {
            currentGrowthStage++;
            lastUpdateTime = currentTime;
        }
        else 
        {
            grown = true;
        }
    }
}