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
        Entities/Ball.cpp
        Entities/Ball.h
        Scenes/GameplayScene.cpp
        Scenes/GameplayScene.h
        main.cpp
        Scenes/MenuScene.cpp
        Scenes/MenuScene.h
        Entities/Platform.cpp
        Entities/Platform.h
        Entities/Brick.cpp
        Entities/Brick.h
        Scenes/EditMapScene.cpp
        Scenes/EditMapScene.h
        Entities/SolidBrick.cpp
        Entities/SolidBrick.h
        Entities/Barrier.cpp
        Entities/Barrier.h)

add_executable(arkanoid ${SOURCE_FILES})