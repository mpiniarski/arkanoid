#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Scene;
class DynamicEntity;

class Entity {
protected:
    int width;
    int height;
    float pos_x;
    float pos_y;

public:
    sf::Sprite sprite;
    Scene *scene;
    virtual int update(){};
    Entity(Scene *scene);
    Entity(Scene *scene, std::string name);
};

