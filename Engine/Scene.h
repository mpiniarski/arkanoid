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
    std::map<std::string,GraphicalEntity*> GraphicalEntityMap;
    std::map<std::string,TextEntity*> TextEntityMap;

protected:
    ResourceManager resourceManager;
    Game *game;

public:
    Scene(Game *game);
    void run();

    void drawOnWindow(GraphicalEntity &drawable);
    void drawOnWindow(TextEntity &drawable);

    int getWindowWidth();
    int getWindowHeight();

protected:
    void initialize();
    void addEntity(Entity *entity);

private:
    void uploadResources();
    virtual void uploadTextures();
    virtual void uploadFonts();
//    virtual void uploadSoundBuffers();

    virtual void createEntities();

    virtual void handleEvents();

    void updateEntities();

    void renderWindow();
};


