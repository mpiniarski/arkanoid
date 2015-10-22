#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <list>

#include "ResourceManager.h"
#include "Game.h"

class GraphicalEntity;
class Entity;

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

    void drawOnWindow(GraphicalEntity &drawable);
//    void drawOnWindow(TextEntity &drawable);

private:
    void renderWindow();
    void updateEntities();

    virtual void createEntities();
    virtual void handleEvents();
    virtual void uploadTextures();

};


