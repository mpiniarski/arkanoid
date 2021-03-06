#pragma once

#include "../Engine/GraphicalEntity.h"

class Barrier : public GraphicalEntity {

public:
    Barrier(Scene *scene, sf::Texture &texture);
    ~Barrier() {};

    //Main GrapficalEntity functionality
    void update() override;
    void manageCollision(GraphicalEntity* ge) override;
};
