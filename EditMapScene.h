#pragma once

#include "Engine/GraphicalEntity.h"
#include "Platform.h"
#include "Ball.h"

#include "Engine/Scene.h"
#include "Brick.h"

namespace TYPE {
    enum { BRICK, SOLIDBRICK, BARRIER };
}
class EditMapScene : public Scene {
private:
    GraphicalEntity *brickCursor;
    int type;
    std::list<GraphicalEntity*>mapEntities;
    std::map<std::string,TextEntity*> TextEntityMap;
public:
    EditMapScene(Game *game);
private:
    void playMap();
    void saveMapToFile(std::string filePath);

    void makeCursor(float pos_x, float pos_y);
    void placeBrick();
    GraphicalEntity* makeBrick();
    void undo();
    void moveEntity(GraphicalEntity* brickCursor, int direction);
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;

    void exitScene(Scene* nextScene = NULL) override;
};
