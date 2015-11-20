#pragma once

#include "../Engine/Scene.h"

class Game;

class BestScoresScene : public Scene {
public:
    BestScoresScene(Game* game);
    ~BestScoresScene(){};

private:
    std::string textFileToScoreList(std::string filePath);

    //Main scene funtionality:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};


