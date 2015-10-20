#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <list>

#include "ResourceManager.h"
#include "Platform.h"
#include "Ball.h"

class Entity;
class Game;
class DynamicEntity;

class Scene{
private:
    std::string name;
    Game *game;

    std::list<Entity*> EntityList;

public:
    Platform *platform;
    Ball *ball;
    Scene(std::string name, Game *game);
    void run();

    ResourceManager resourceManager;
private:
    void handleEvents();
    void updateEntities();
    void renderWindow();
};

