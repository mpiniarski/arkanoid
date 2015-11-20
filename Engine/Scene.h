#pragma once

#include "Game.h"
#include "ResourceManager.h"

#include <list>
#include <map>

class Entity;
class GraphicalEntity;
class TextEntity;

namespace DIRECTION {
    enum { UP, DOWN, LEFT, RIGHT };
};

class Scene{
private:
    std::list<Entity*> EntityList;
    Scene* nextScene;
    bool endScene;

protected:
    Game *game;
    std::map<std::string,TextEntity*> TextEntityMap;
    ResourceManager resourceManager;

public:
    Scene(Game *game);
    virtual ~Scene();

    void run();
    virtual void exitScene(Scene* nextScene = NULL);

    void drawOnWindow(sf::Drawable &drawable);
    int getWindowWidth();
    int getWindowHeight();

protected:
    void initialize();
    void addEntity(Entity *entity);
    void removeEntity(Entity *entity);
    void moveTextEntitiesToFront();

private:
    void updateEntities();
    void renderWindow();

    virtual void uploadResources();
    virtual void createEntities();
    virtual void handleEvents();
};


