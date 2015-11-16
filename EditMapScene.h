#pragma once

#include "Engine/GraphicalEntity.h"
#include "Platform.h"
#include "Ball.h"

#include "Engine/Scene.h"
#include "Brick.h"

class EditMapScene : public Scene {
private:
    Brick *brickCursor;
    std::list<GraphicalEntity*>mapEntities;
public:
    EditMapScene(Game *game);
private:
    void playMap();
    void saveMapToFile(std::string filePath);

    void makeCursor(float pos_x, float pos_y);
    void placeBrick();
    void undo();
    void moveEntity(Brick* brickCursor, int direction);
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;

    void exitScene(Scene* nextScene = NULL) override;
};
