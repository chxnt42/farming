#include "game.h"
#include "textureManager.h"
#include <memory>
#include <raylib.h>
#include <functional>
#include <iostream>

#include "plant.h"


namespace ui
{

    class draggableContainer;

    class baseUiItem
    {
        public:
        baseUiItem(draggableContainer* _parent,Texture2D _itemTexture,float _scale = 1.0f);

        draggableContainer* parentContainer;

        Texture2D itemTexture;
        Vector2 position;

        float scale = 1.0f;

        void draw();

        virtual void onDragEnd(){};
    };


    class carrotUiItem : public baseUiItem
    {
        public:
        carrotUiItem(draggableContainer* _parent,Texture2D _itemTexture,float _scale = 1.0f) : baseUiItem(_parent,_itemTexture,_scale){};
        
        void onDragEnd() override;
    };







    class draggableContainer
    {
        public:
        draggableContainer(Rectangle _bounds)
        {
            bounds = _bounds;
        }


        std::unique_ptr<baseUiItem> item;

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
