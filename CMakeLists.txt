cmake_minimum_required(VERSION 3.15.3)
project(ExaltedJupiter C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_DIRS})
include_directories(inc)

add_executable(ExaltedJupiter main.c src/game.c)
target_link_libraries(ExaltedJupiter ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mconsole -mwindows)