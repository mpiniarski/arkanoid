#pragma once

#include "../Engine/Scene.h"

class Ball;
class Platform;


class GameplayScene : public Scene {
public:
    int entitiesLeft;
private:
    bool isKeyHeld[4];
    unsigned int points;
    unsigned int levelNumber;

    Platform *platform;
    Ball *ball;

public:
    GameplayScene(Game *game, int levelNumber, int points);
    GameplayScene(Game *game, std::list<GraphicalEntity*> entityList);
    void addPoints(int points);
    void finishGame();
private:
    void loadMapFromFile(std::string filePath);

    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;


    void exitScene(Scene* nextScene) override;
};
