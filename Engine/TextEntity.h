#pragma once

#include <SFML/Graphics/Text.hpp>
#include "Entity.h"

class TextEntity : public Entity, public sf::Text {

public:
    TextEntity(Scene *scene, std::string context, const sf::Font &font);

    void draw() override;
    void update() override { };

    float getWidth() {return getLocalBounds().width;};
    float getHeight() {return getLocalBounds().height;}
};

