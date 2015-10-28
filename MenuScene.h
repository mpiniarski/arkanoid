#pragma once

#include "Engine/TextEntity.h"

#include "Engine/Scene.h"

namespace OPTION {
    enum { NEWGAME, EDITMAP, EXIT };
}

class MenuScene : public Scene {
private:
    TextEntity *title;
    TextEntity *new_game;
    TextEntity *edit_map;
    TextEntity *exit;
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


