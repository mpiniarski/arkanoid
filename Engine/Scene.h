#pragma once

#include <string>
#include <unordered_map>
#include <list>

#include "Game.h"
#include "ResourceManager.h"


namespace DIRECTION {
    enum { UP, DOWN, LEFT, RIGHT };
};

class Entity;
class GraphicalEntity;
class TextEntity;



class Scene{
private:
    std::list<Entity*> EntityList;

protected:
    ResourceManager resourceManager;
    Game *game;
    std::map<std::string,TextEntity*> TextEntityMap;

public:
    Scene(Game *game);
    void run();

    void drawOnWindow(sf::Drawable &drawable);

    int getWindowWidth();
    int getWindowHeight();

protected:
    void initialize();
    void addEntity(Entity *entity);

private:
    virtual void uploadResources();
    virtual void createEntities();

    virtual void handleEvents();

    void updateEntities();

    void renderWindow();

};


