#include "plant.h"
#include "game.h"
#include "raylib.h"
#include "textureManager.h"
#include <iostream>




const std::unordered_map<Plant::PositiveEffects, std::string> Plant::positiveEffectNames = {
    {PositiveEffects::JUICY, "Juicy"},
    {PositiveEffects::REFRESHING, "Refreshing"},
    {PositiveEffects::AWAKENING, "Awakening"},
    {PositiveEffects::MIND_CLEARING, "Mind Clearing"},
    {PositiveEffects::HEALING, "Healing"}
};

const std::unordered_map<Plant::NegativeEffects, std::string> Plant::negativeEffectNames = {
    {NegativeEffects::SHOCKING, "Shocking"},
    {NegativeEffects::BURNING, "Burning"},
    {NegativeEffects::SADNESS, "Sadness"},
    {NegativeEffects::TOXIC, "Toxic"},
    {NegativeEffects::PARALYSIS, "Paralysis"}
};


const std::unordered_map<Plant::PositiveEffects, int> Plant::positiveEffectValues = {
    {PositiveEffects::JUICY, 5},
    {PositiveEffects::REFRESHING, 10},
    {PositiveEffects::AWAKENING, 20},
    {PositiveEffects::MIND_CLEARING, 30},
    {PositiveEffects::HEALING, 40}
};

const std::unordered_map<Plant::NegativeEffects, int> Plant::negativeEffectValues = {
    {NegativeEffects::SHOCKING, -5},
    {NegativeEffects::BURNING, -10},
    {NegativeEffects::SADNESS, -20},
    {NegativeEffects::TOXIC, -30},
    {NegativeEffects::PARALYSIS, -40}
};



Plant::Plant(std::vector<int> _positiveEffects,std::vector<int> _negativeEffects)
{
    positiveEffectList = _positiveEffects;
    negativeEffectList = _negativeEffects;
}


const std::string& Plant::getPositiveEffectName(PositiveEffects effect) {
    return positiveEffectNames.at(effect);
}

const std::string& Plant::getNegativeEffectName(NegativeEffects effect) {
    return negativeEffectNames.at(effect);
}


int Plant::getPositiveEffectValue(PositiveEffects effect) {
    return positiveEffectValues.at(effect);
}

int Plant::getNegativeEffectValue(NegativeEffects effect) {
    return negativeEffectValues.at(effect);
}


void Plant::calculatePlantValue()
{
    for(const auto& negativeEffect : negativeEffectList)
    {
        value += getNegativeEffectValue(static_cast<NegativeEffects>(negativeEffect));
    }

    for(const auto& posativeEffect : positiveEffectList)
    {
        value += getPositiveEffectValue(static_cast<PositiveEffects>(posativeEffect));
    }
}


void Plant::addEffect(NegativeEffects negativeEffect)
{
    negativeEffectList.push_back(static_cast<int>(negativeEffect));

    value += getNegativeEffectValue(negativeEffect);
}

 void Plant::addEffect(PositiveEffects posativeEffect)
 {
    positiveEffectList.push_back(static_cast<int>(posativeEffect));

    value += getPositiveEffectValue(posativeEffect);
 }

Carrot::Carrot(std::vector<int> positiveEffects,std::vector<int> negativeEffects) : Plant(positiveEffects,negativeEffects) 
{
    plantName = "Carrot";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::CARROT_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::CARROT_SHEET);
    growthSpeed = 2.15;
    value = 10;
}

Sweetpea::Sweetpea(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Sweetpea";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::SWEETPEA_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::SWEETPEA_SHEET);
    growthSpeed = 2.15;
}


Squash::Squash(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Squash";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::SQUASH_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::SQUASH_SHEET);
    growthSpeed = 2.15;
}

Lettuce::Lettuce(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Lettuce";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::LETTUCE_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::LETTUCE_SHEET);
    growthSpeed = 2.15;
}

Orange::Orange(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Orange";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::ORANGE_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::ORANGE_SHEET);
    growthSpeed = 2.15;
}

Spinach::Spinach(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Spinach";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::SPINACH_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::SPINACH_SHEET);
    growthSpeed = 2.15;
}

Blueberry::Blueberry(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Blueberry";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::BLUEBERRY_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::BLUEBERRY_SHEET);
    growthSpeed = 2.15;
}

Pumpkin::Pumpkin(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Pumpkin";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::PUMPKIN_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::PUMPKIN_SHEET);
    growthSpeed = 2.15;
}

Cabbage::Cabbage(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Cabbage";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::CABBAGE_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::CABBAGE_SHEET);
    growthSpeed = 2.15;
}

Parsnip::Parsnip(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Parsnip";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::PARSNIP_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::PARSNIP_SHEET);
    growthSpeed = 2.15;
}

Broccoli::Broccoli(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Broccoli";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::BROCCOLI_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::BROCCOLI_SHEET);
    growthSpeed = 2.15;
}

Buttercup::Buttercup(std::vector<int> positiveEffects, std::vector<int> negativeEffects) : Plant(positiveEffects, negativeEffects)
{
    plantName = "Buttercup";
    plantIconTexture = Game::instance().m_textureManager->getTexture(TextureType::BUTTERCUP_ICON);
    growthTextureSheet = Game::instance().m_textureManager->getTexture(TextureType::BUTTERCUP_SHEET);
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
            if(currentGrowthStage == 4)
            {
                grown = true;
            }
        }
    }
}