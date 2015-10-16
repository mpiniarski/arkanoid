#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Scene;

class Entity {
public:
    sf::Sprite *sprite;
    Scene *scene;
    Entity(Scene *scene);
    Entity(Scene *scene, string name);
};

