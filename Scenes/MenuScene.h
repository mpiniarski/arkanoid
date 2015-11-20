#pragma once

#include "../Engine/TextEntity.h"
#include "../Engine/GraphicalEntity.h"
#include "../Engine/Scene.h"

namespace OPTION {
    enum { NEWGAME, EDITMAP, BESTSCORES, EXIT };
}

class MenuScene : public Scene {
private:
    int chosenOption;

public:
    MenuScene(Game *game);
    ~MenuScene(){};
private:
    void changeOption(int direction);
    void markOption();

    //Main scene funtionality:
    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};


