cmake_minimum_required(VERSION 3.3)
project(arkanoid)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -lsfml-system -lsfml-window -lsfml-graphics")

set(SOURCE_FILES
    main.cpp Engine/Game.h Engine/Game.cpp)

add_executable(arkanoid ${SOURCE_FILES})