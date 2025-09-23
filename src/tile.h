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
    Tile() = default;


private:

};

#endif