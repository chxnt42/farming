#ifndef TILE_H
#define TILE_H

#pragma once

#include <memory>
#include "plant.h"


class Tile
{
public:
    std::unique_ptr<Plant> plant;

    void draw();
    void update();
    Tile() = default;


private:

};

#endif