#pragma once

#include "../Engine/GraphicalEntity.h"

class GameplayScene;
class Platform : public GraphicalEntity {

public:
    Platform(Scene *scene, sf::Texture &texture);
    ~Platform() {};

    //Main GrapficalEntity functionality
    void update() override;
    void manageCollision(GraphicalEntity* ge) override {};
};

