#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <list>

#include "ResourceManager.h"
#include "Game.h"

class Entity;
class DynamicEntity;

class Scene{
private:

protected:
    std::string name;
    Game *game;

    void initialize();

    std::list<Entity*> EntityList;

    void uploadResources();

public:
    Scene(std::string name, Game *game);
    void run();
    ResourceManager resourceManager;
    void addEntity(Entity *entity);

private:
    void renderWindow();
    void updateEntities();

    virtual void createEntities();
    virtual void handleEvents();
    virtual void uploadTextures();
};


