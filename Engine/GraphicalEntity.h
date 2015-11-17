#pragma once

#include "Entity.h"

#include <SFML/Graphics/Sprite.hpp>

class GraphicalEntity : public Entity, public sf::Sprite {
protected:
    float movingHorizontal;
    float movingVertical;
    double velocity;
public:
    GraphicalEntity(Scene *scene, std::string entityType, const sf::Texture &texture);
    virtual ~GraphicalEntity() {};

    void draw();
    virtual void update() ;

    float getWidth();
    float getHeight();
    void stretchToWindowSize();
//    void unifyWithResolutoin(int width, int height);

    void changeDirection(int direction);
    void resetDirection(int direction);

    virtual void manageCollision(GraphicalEntity* ge){};

protected:
    void makeStep();
};


