#pragma once

#include "Engine/GraphicalEntity.h"

class GameplayScene;
class Platform : public GraphicalEntity {

public:
    Platform(GameplayScene *scene, const sf::Texture &texture);
    int update();
};

