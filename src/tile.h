#ifndef TILE_H
#define TILE_H

#include <utility>
#pragma once

#include <memory>
#include "plant.h"


class Tile
{
public:
    std::unique_ptr<Plant> plant;

    void draw(const std::pair<int,int>& gridPos);
    void update();


    std::unique_ptr<Plant> harvest();
    Tile() = default;


private:

};

#endif