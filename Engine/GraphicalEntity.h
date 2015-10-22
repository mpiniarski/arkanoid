#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class GraphicalEntity : public Entity, public sf::Sprite{

public:
    GraphicalEntity(Scene *scene, const sf::Texture &texture);

    int draw();

    void makeStep();
    void changeDirection(int direction);
    void resetDirection(int direction);

    float getWidth() {return getTexture()->getSize().x;};
    float getHeight() {return getTexture()->getSize().y;}
};


