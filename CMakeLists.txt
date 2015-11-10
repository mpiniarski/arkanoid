cmake_minimum_required(VERSION 3.3)
project(arkanoid)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lsfml-system -lsfml-window -lsfml-graphics")

set(SOURCE_FILES
    Engine/Entity.cpp
    Engine/Entity.h
    Engine/Game.cpp
    Engine/Game.h
    Engine/GraphicalEntity.cpp
    Engine/GraphicalEntity.h
    Engine/ResourceManager.cpp
    Engine/ResourceManager.h
    Engine/Scene.cpp
    Engine/Scene.h
    Engine/TextEntity.cpp
    Engine/TextEntity.h
    Ball.cpp
    Ball.h
    GameplayScene.cpp
    GameplayScene.h
    main.cpp
    MenuScene.cpp
    MenuScene.h
    Platform.cpp
    Platform.h Brick.cpp Brick.h)

add_executable(arkanoid ${SOURCE_FILES})