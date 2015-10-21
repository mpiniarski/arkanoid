#pragma once

#include "Engine/Scene.h"

class Platform;
class Ball;

class GameplayScene : public Scene {
public:
    GameplayScene(const std::string &name, Game *game);

    Platform *platform;
    Ball *ball;

    void uploadTextures() override;
    void createEntities() override;
    void handleEvents() override;
};
