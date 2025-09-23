#ifndef PLANT_H
#define PLANT_H

#pragma once
#include "raylib.h"
#include "textureManager.h"



class Game;


class Plant
{
public:


    Texture2D growthTextureSheet;
    int currentGrowthStage = 0 ; // 4th growth stage is the last texture



    float growthspeed;
    float lastUpdateTime;


    bool grown = false;
    void draw(const std::pair<int,int>& gridPos);
    void update();
        


private:

};


class Carrot : public Plant
{
    public:
    Carrot();

};

#endif