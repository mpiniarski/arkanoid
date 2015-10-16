cmake_minimum_required(VERSION 3.3)
project(arkanoid)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lsfml-system -lsfml-window -lsfml-graphics")

set(SOURCE_FILES
        Engine/Game.cpp
        Engine/Game.h
        Engine/Scene.cpp
        Engine/Scene.h
        Engine/Entity.cpp
        Engine/Entity.h
        Engine/ResourceManager.cpp
        Engine/ResourceManager.h
        main.cpp)

add_executable(arkanoid ${SOURCE_FILES})
