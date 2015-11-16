#pragma once

#include "Engine/GraphicalEntity.h"

class Barrier : public GraphicalEntity {

public:
    Barrier(Scene *scene, const sf::Texture &texture);
    ~Barrier() {};
    void update() override;

    void manageCollision(GraphicalEntity* ge) override;
};
