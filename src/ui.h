#include "game.h"
#include "textureManager.h"
#include <memory>
#include <raylib.h>
#include <functional>
#include <iostream>

#include "plant.h"
#include <queue>


namespace ui
{


   

    class draggableContainer;



    class PlantFactory {
    public:
        static std::unique_ptr<Plant> createPlant(Plant::PlantType type) {
            switch(type) {
                case Plant::PlantType::CARROT:
                    return std::make_unique<Carrot>();
                case Plant::PlantType::SWEETPEA:
                    return std::make_unique<Sweetpea>();
                case Plant::PlantType::SQUASH:
                    return std::make_unique<Squash>();
                case Plant::PlantType::LETTUCE:
                    return std::make_unique<Lettuce>();
                case Plant::PlantType::ORANGE_FRUIT:
                    return std::make_unique<Orange>();
                case Plant::PlantType::SPINACH:
                    return std::make_unique<Spinach>();
                case Plant::PlantType::BLUEBERRY:
                    return std::make_unique<Blueberry>();
                case Plant::PlantType::PUMPKIN:
                    return std::make_unique<Pumpkin>();
                case Plant::PlantType::CABBAGE:
                    return std::make_unique<Cabbage>();
                case Plant::PlantType::PARSNIP:
                    return std::make_unique<Parsnip>();
                case Plant::PlantType::BROCCOLI:
                    return std::make_unique<Broccoli>();
                case Plant::PlantType::BUTTERCUP:
                    return std::make_unique<Buttercup>();
                default:
                    return nullptr;
            }
        }
    };

    class baseUiItem
    {
        public:
        Plant::PlantType plantType;
        std::unique_ptr<Plant> plant;

        baseUiItem(draggableContainer* _parent,float _scale = 1.0f,Plant::PlantType type = Plant::PlantType::CARROT);
        


        draggableContainer* parentContainer;
        Vector2 position;
        float scale = 1.0f;

        void draw();
        virtual void onDragEnd();
    };




    class draggableContainer
    {
        public:
        draggableContainer(Rectangle _bounds);


        std::unique_ptr<baseUiItem> item;

        Rectangle bounds;
        bool isDragging = false;



        virtual void onStartDrag();
        virtual void onDrag();
        virtual void onStopDrag();
        
        void onHover();
        

        void update();
        void draw();
        
    };

    //void renderPlantCard(std::unique_ptr<baseUiItem>& UIItem);
    void renderPlantCard(std::unique_ptr<Plant>& plantItem);


    void drawMoney();


    
};
