#include "game.h"
#include "textureManager.h"
#include <raylib.h>
#include <functional>
#include <iostream>


namespace ui
{
    class draggableContainer
    {
        public:
        draggableContainer(TextureType itemTextureType)
        {
            itemTexture = Game::instance().m_textureManager->getTexture(itemTextureType);
        }

        Texture2D itemTexture;

        Rectangle bounds;
        bool isDragging = false;



        virtual void onStartDrag();
        virtual void onDrag();
        virtual void onStopDrag();
        
        void onHover() {};
        

        void update();
        void draw();
        
    };
};
