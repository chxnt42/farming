#include "tile.h"
#include "game.h"




void Tile::draw(const std::pair<int,int>& gridPos) 
{

    DrawTexture(Game::instance().m_textureManager->getTexture(TextureType::DIRT_TILE), gridPos.first * Game::instance().m_tileSize, gridPos.second * Game::instance().m_tileSize,
                    WHITE);

    if(!plant){return;}
    
    plant->draw(gridPos);
}


void Tile::update()
{
    if(!plant){return;}

    if(!plant->grown)
    {
        plant->update();
    }
}