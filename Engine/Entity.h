#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Scene.h"

using namespace std;

class Entity {
public:
    sf::Sprite *sprite;
    Scene *scene;
    Entity(Scene *scene);
    Entity(Scene *scene, string name);
};

