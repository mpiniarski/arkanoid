#pragma once

#include "../Engine/Scene.h"

class Ball;
class Platform;

class GameplayScene : public Scene {
private:
    bool isKeyHeld[4];
    int points;
    int levelNumber;
    int entitiesLeft;

    Platform *platform;
    Ball *ball;
public:
    GameplayScene(Game *game, int levelNumber, int points);
    GameplayScene(Game *game, std::list<GraphicalEntity*> entityList);
    ~GameplayScene() {};

    void addPoints(int points);
    void subtractEntity();
    void exitScene(Scene* nextScene) override; // overrides what happens, when You want to exitScene, and dont pass nextScene to this method

    void generateColorBonus();
    void generatePlatformResizeBonus();

private:
    void loadMapFromFile(std::string filePath);
    void saveScore(std::string filePath);
    void winGame();

    //Main scene funtionality:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};
