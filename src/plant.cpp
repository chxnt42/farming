#include "plant.h"
#include "game.h"
#include "raylib.h"
#include "textureManager.h"
#include <iostream>




const std::unordered_map<Plant::PositiveEffects, std::string> Plant::positiveEffectNames = {
    {PositiveEffects::JUICY, "Juicy"},
    {PositiveEffects::REFRESHING, "Refreshing"},
    {PositiveEffects::HEALING, "Healing"},
    {PositiveEffects::MIND_CLEARING, "Mind Clearing"}
};

const std::unordered_map<Plant::NegativeEffects, std::string> Plant::negativeffectNames = {
    {NegativeEffects::PARALYSIS, "Paralysis"},
    {NegativeEffects::SADNESS, "Sadness"},
    {NegativeEffects::TOXIC, "Toxic"},
    {NegativeEffects::ELECTRIC, "Electric"},
    {NegativeEffects::FLAMMABLE, "Flammable"}
};


const std::unordered_map<Plant::PositiveEffects, int> Plant::positiveEffectValues = {
    {PositiveEffects::JUICY, 10},
    {PositiveEffects::REFRESHING, 20},
    {PositiveEffects::HEALING, 30},
    {PositiveEffects::MIND_CLEARING, 40},
};

const std::unordered_map<Plant::NegativeEffects, int> Plant::negativeffectValues = {
    {NegativeEffects::PARALYSIS, -30},
    {NegativeEffects::SADNESS, -20},
    {NegativeEffects::TOXIC, -25},
    {NegativeEffects::ELECTRIC, -5},
    {NegativeEffects::FLAMMABLE, -10}
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
    return negativeffectNames.at(effect);
}


int Plant::getPositiveEffectValue(PositiveEffects effect) {
    return positiveEffectValues.at(effect);
}

int Plant::getNegativeEffectValue(NegativeEffects effect) {
    return negativeffectValues.at(effect);
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