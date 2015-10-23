#pragma once

#include "Engine/Scene.h"

namespace OPTION {
    enum { NEWGAME, EDITMAP, EXIT };
}

class MenuScene : public Scene {
private:
    int chosenOption;
    void changeOption(int direction);
    void markOption();
public:
    MenuScene(const std::string &name, Game *game);
    TextEntity *title;
    TextEntity *new_game;
    TextEntity *edit_map;
    TextEntity *exit;

    void uploadTextures() override;
    void uploadFonts() override;
    void createEntities() override;
    void handleEvents() override;
};


