#ifndef PLANT_H
#define PLANT_H

#include <vector>
#pragma once
#include "raylib.h"
#include "textureManager.h"
#include <unordered_map>



class Game;




class Plant
{
public:


    enum class PositiveEffects 
    {
        JUICY,
        REFRESHING,
        HEALING,
        MIND_CLEARING
    };


    enum class NegativeEffects 
    {
        PARALYSIS,
        SADNESS,
        TOXIC,
        ELECTRIC,
        FLAMMABLE
    };

    Plant(std::vector<int> positiveEffects = {},std::vector<int> negativeEffects = {});


    std::vector<int> positiveEffectList;
    std::vector<int> negativeEffectList;

    std::string plantName;

    Texture2D plantIconTexture;
    Texture2D growthTextureSheet;
    int currentGrowthStage = 0 ; // 4th growth stage is the last texture

    float growthSpeed;
    float lastUpdateTime = 0;

    int value;

    bool grown = false;


    void draw(const std::pair<int,int>& gridPos);
    void update();


    void calculatePlantValue();

    void addEffect(NegativeEffects negativeEffect);
    void addEffect(PositiveEffects posativeEffect);
        

    static const std::string& getPositiveEffectName(PositiveEffects effect);
    static const std::string& getNegativeEffectName(NegativeEffects effect);

    static  int getPositiveEffectValue(PositiveEffects effect);
    static  int getNegativeEffectValue(NegativeEffects effect);

private:
    static const std::unordered_map<PositiveEffects, std::string> positiveEffectNames;
    static const std::unordered_map<NegativeEffects, std::string> negativeffectNames;

    static const std::unordered_map<PositiveEffects, int> positiveEffectValues;
    static const std::unordered_map<NegativeEffects, int> negativeffectValues;

};


class Carrot : public Plant
{
    public:
    Carrot(std::vector<int> positiveEffects = {},std::vector<int> negativeEffects = {});

};

#endif