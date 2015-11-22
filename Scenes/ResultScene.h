#pragma once

#include "../Engine/Scene.h"

namespace RESULT {
    enum { WIN, LOSE };
}

class ResultScene : public Scene {
private:
    int result;
    int points;

public:
    ResultScene(Game *game, int points, int entitiesLeft);
    ~ResultScene(){};

private:
    //Main scene funtionality:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};

