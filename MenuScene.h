#pragma once

#include "Engine/Scene.h"

class MenuScene : public Scene {
public:
    MenuScene(const std::string &name, Game *game);

    TextEntity *text;

    void uploadTextures() override;
    void uploadFonts() override;
    void createEntities() override;
    void handleEvents() override;
};


