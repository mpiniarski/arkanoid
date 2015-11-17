#pragma once

#include "../Engine/GraphicalEntity.h"

class Brick : public GraphicalEntity {

public:
    Brick(Scene *scene, const sf::Texture &texture);
    ~Brick() {};
    void update() override;

    void manageCollision(GraphicalEntity* ge) override;
};

