#pragma once

#include "Engine/GraphicalEntity.h"
#include "Platform.h"
#include "Ball.h"

#include "Engine/Scene.h"
#include "Brick.h"

class EditMapScene : public Scene {
private:
    Brick *brickCursor;
    Ball *ball;
    std::list<Entity*>mapEntities;
public:
    EditMapScene(Game *game);
private:
    void loadMap();

    void moveEntity(Brick* brickCursor, int direction);
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;

    void exitScene(Scene* nextScene = NULL) override;
};
