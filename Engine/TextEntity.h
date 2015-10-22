#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class TextEntity : public Entity, public sf::Text {

public:
    TextEntity(Scene *scene, std::string context, const sf::Font &font);

    int draw();
    int update(){};

    float getWidth() {return getLocalBounds().width;};
    float getHeight() {return getLocalBounds().height;}
};

