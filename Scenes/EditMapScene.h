#pragma once

#include "../Engine/GraphicalEntity.h"
#include "../Engine/Scene.h"

namespace TYPE {
    enum { BRICK, SOLIDBRICK, BARRIER };
}
class EditMapScene : public Scene {
private:
    int chosenCursor;
    GraphicalEntity *brickCursor;
    std::list<GraphicalEntity*>mapEntities; // hold all Grapghial Entities which create map

public:
    EditMapScene(Game *game);
    ~EditMapScene(){};

    void exitScene(Scene* nextScene = NULL) override; // overrides what happens, when You want to exitScene, and dont pass nextScene to this method
private:
    void moveEntity(GraphicalEntity* brickCursor, int direction);
    void makeCursor(float pos_x, float pos_y);
    void placeBrick();
    GraphicalEntity* makeBrick();
    void undo();

    void saveMapToFile(std::string filePath);
    void playMap();

    //Main scene funtionality:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;

    void loadMapFromFile(std::string filePath);
};
