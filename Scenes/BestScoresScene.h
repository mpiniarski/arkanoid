#pragma once

#include "../Engine/Scene.h"

class Game;

class BestScoresScene : public Scene {
public:
    BestScoresScene(Game* game);

private:
    std::string textFileToScoreList(std::string filePath);
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};


