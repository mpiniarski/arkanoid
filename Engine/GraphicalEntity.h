#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "Entity.h"

class GraphicalEntity : public Entity, public sf::Sprite {
protected:
    float movingHorizontal;
    float movingVertical;
    double velocity;
public:
    GraphicalEntity(Scene *scene, const sf::Texture &texture);
    virtual ~GraphicalEntity() {};

    void draw();
    virtual void update() ;

    float getWidth();
    float getHeight();

    void changeDirection(int direction);
    void resetDirection(int direction);

    virtual void manageCollision(GraphicalEntity* ge){};

protected:
    void makeStep();
};


