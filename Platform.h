#pragma once

#include "Engine/GraphicalEntity.h"

class GameplayScene;
class Platform : public GraphicalEntity {

public:
    Platform(Scene *scene, const sf::Texture &texture);
    void update() override;

    void manageCollision(GraphicalEntity* ge){};
};

