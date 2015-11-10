#pragma once

#include <SFML/Graphics/Text.hpp>
#include "Entity.h"

class TextEntity : public Entity, public sf::Text {

public:
    TextEntity(Scene *scene, std::string content, const sf::Font &font);
    virtual ~TextEntity() {};

    void draw() override;
    void update() override { };

    float getWidth() {return getLocalBounds().width;};
    float getHeight() {return getLocalBounds().height;}
};

