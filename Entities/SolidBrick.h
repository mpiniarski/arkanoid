#pragma once

#include "../Engine/GraphicalEntity.h"

class SolidBrick : public GraphicalEntity {
private:
    int lives;

public:
    SolidBrick(Scene *scene, const sf::Texture &texture);
    ~SolidBrick() {};

    //Main GrapficalEntity functionality
    void update() override;
    void manageCollision(GraphicalEntity* ge) override;
};

