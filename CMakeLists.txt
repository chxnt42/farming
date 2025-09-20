cmake_minimum_required(VERSION 3.10.0)
project(farming VERSION 0.1.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)


FetchContent_MakeAvailable(raylib)

include(FetchContent)
FetchContent_Declare(
    raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG 4.0
)


FetchContent_MakeAvailable(raygui)

add_executable(farming src/main.cpp src/utils.h src/game.cpp src/tile.cpp src/textureManager.cpp src/ui.cpp) 
target_link_libraries(farming PRIVATE raylib)

target_include_directories(farming PRIVATE ${raygui_SOURCE_DIR}/src)