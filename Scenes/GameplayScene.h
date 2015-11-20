#pragma once

#include "../Engine/Scene.h"

class Ball;
class Platform;


class GameplayScene : public Scene {
private:
    bool isKeyHeld[4];
    unsigned int points;
    unsigned int levelNumber;
    int entitiesLeft;

    Platform *platform;
    Ball *ball;

public:
    GameplayScene(Game *game, int levelNumber, int points);
    GameplayScene(Game *game, std::list<GraphicalEntity*> entityList);
    void addPoints(int points);
    void subtractEntity();
private:
    void loadMapFromFile(std::string filePath);
    void saveScore(std::string filePath);
    void winGame();

    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;


    void exitScene(Scene* nextScene) override;
};
