#pragma once

#include "../Engine/Scene.h"

namespace RESULT {
    enum { WIN, LOSE };
}

class ResultScene : public Scene {
private:
    std::map<std::string,TextEntity*> TextEntityMap;
    int result;
    int points;

public:
    ResultScene(Game *game, int points, int entitiesLeft);

private:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};

