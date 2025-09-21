#include "tile.h"




void Tile::draw()
{
    if(!plant){return;}
    
    plant->draw();
}