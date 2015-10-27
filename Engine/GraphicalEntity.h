#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "Entity.h"

namespace DIRECTION {
    enum { UP, DOWN, LEFT, RIGHT };
    enum { STOP, MOVING, HELD };
};

class GraphicalEntity : public Entity, public sf::Sprite {
protected:
    int movingRight;
    int movingLeft;
    int movingUp;
    int movingDown;
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


