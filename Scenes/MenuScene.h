#pragma once

#include "../Engine/TextEntity.h"
#include "../Engine/GraphicalEntity.h"
#include "../Engine/Scene.h"

namespace OPTION {
    enum { NEWGAME, EDITMAP, BESTSCORES, EXIT };
}

class MenuScene : public Scene {
private:
    std::map<std::string,TextEntity*> TextEntityMap;
    int chosenOption;
public:
    MenuScene(Game *game);
private:
    void changeOption(int direction);
    void markOption();

    void uploadResources() override;
    void createEntities() override;
    void handleEvents() override;
};


