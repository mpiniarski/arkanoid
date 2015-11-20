#pragma once

#include "Entity.h"

#include <SFML/Graphics/Sprite.hpp>

class GraphicalEntity : public Entity, public sf::Sprite {
protected:
    float movingHorizontal;
    float movingVertical;
    double velocity;

public:
    GraphicalEntity(Scene *scene, std::string entityType, sf::Texture &texture);
    virtual ~GraphicalEntity() {};

    void draw();
    virtual void update(); // virtual cause can change in children-classes

    void changeDirection(int direction);
    void resetDirection(int direction);
    virtual void manageCollision(GraphicalEntity* ge);

    float getWidth();
    float getHeight();
    void stretchToWindowSize();

protected:
    void makeStep();
};


