#pragma once

#include "Game.h"
#include "ResourceManager.h"

#include <string>
#include <unordered_map>
#include <list>


namespace DIRECTION {
    enum { UP, DOWN, LEFT, RIGHT };
};

class Entity;
class GraphicalEntity;
class TextEntity;



class Scene{
private:
    std::list<Entity*> EntityList;
    Scene* nextScene;
    bool endScene;

protected:
    Game *game;
    std::map<std::string,TextEntity*> TextEntityMap;
    void moveTextEntitiesToFront();

public:
    Scene(Game *game);
    virtual ~Scene();
    void run();

    void drawOnWindow(sf::Drawable &drawable);

    int getWindowWidth();
    int getWindowHeight();

    virtual void exitScene(Scene* nextScene = NULL);

    ResourceManager resourceManager;
protected:
    void initialize();
    void addEntity(Entity *entity);
    void removeEntity(Entity *entity);

private:
    virtual void uploadResources();
    virtual void createEntities();

    virtual void handleEvents();

    void updateEntities();

    void renderWindow();

};


