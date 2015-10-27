#pragma once

#include <string>
#include <unordered_map>
#include <list>

#include "Game.h"
#include "ResourceManager.h"
#include "Entity.h"
#include "GraphicalEntity.h"
#include "TextEntity.h"


class Scene{
private:
    std::list<Entity*> EntityList;
    std::map<std::string,GraphicalEntity*> GraphicalEntityMap;
    std::map<std::string,TextEntity*> TextEntityMap;

protected:
    Game *game;
    ResourceManager resourceManager;

public:
    Scene(Game *game);
    void run();

    void drawOnWindow(GraphicalEntity &drawable);
    void drawOnWindow(TextEntity &drawable);

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


