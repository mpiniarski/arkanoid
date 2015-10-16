#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <list>

#include "ResourceManager.h"

class Entity;
class Game;
class DynamicEntity;

class Scene{
private:
    std::string name;
    Game *game;
    DynamicEntity *platform;

    std::list<Entity*> EntityList;

public:
    Scene(std::string name, Game *game);
    void run();

    ResourceManager resourceManager;
private:
    void handleEvents();
    void updateEntities();
    void renderWindow();
};

