#pragma once

#include "Platform.h"
#include "Ball.h"

#include "Engine/Scene.h"


class GameplayScene : public Scene {
private:
    bool isKeyHeld[4];
    Platform *platform;
    Ball *ball;
public:
    GameplayScene(Game *game);
private:
    void uploadTextures() override;
    void createEntities() override;
    void handleEvents() override;
};
