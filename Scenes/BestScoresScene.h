#pragma once

#include "../Engine/Scene.h"

class Game;

class BestScoresScene : public Scene {
public:
    BestScoresScene(Game* game);

private:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};


