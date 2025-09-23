#ifndef PLANT_H
#define PLANT_H

#include "raylib.h"
#pragma once



class Plant
{
public:
    Texture2D growthTextureSheet;
    float growthspeed;
    void draw(){};
    
    void update();
        


private:

};


class Carrot : public Plant
{
    public:

    float growthspeed = 30;
};

#endif