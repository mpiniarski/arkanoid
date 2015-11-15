#pragma once


#include "Engine/Scene.h"

class Ball;
class Platform;


class GameplayScene : public Scene {
private:
    bool isKeyHeld[4];

    Platform *platform;
    Ball *ball;

public:
    GameplayScene(Game *game, int levelNumber);
    GameplayScene(Game *game, std::list<GraphicalEntity*> entityList);
private:
    void loadMapFromFile(std::string filePath);

    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;


    void exitScene(Scene* nextScene) override;
};
