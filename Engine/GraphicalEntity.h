#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "Entity.h"

class GraphicalEntity : public Entity, public sf::Sprite {
protected:
    int movingHorizontal;
    int movingVertical;
    double velocity;
public:
    GraphicalEntity(Scene *scene, const sf::Texture &texture);

    void draw() ;
    virtual void update() ;

    float getWidth();
    float getHeight();

    void changeDirection(int direction);
    void resetDirection(int direction);

    virtual void manageCollision(GraphicalEntity* ge){};

protected:
    void makeStep();
};


