#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Scene;

class Entity {
public:
    sf::Sprite sprite;
    Scene *scene;
    Entity(Scene *scene);
    Entity(Scene *scene, std::string name);
};

