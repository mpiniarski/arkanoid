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
    GameplayScene(Game *game);
    void gameOver();
private:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};
