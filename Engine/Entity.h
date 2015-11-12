#pragma once

#include "Scene.h"


class Entity{
protected:
public:
    Scene *scene;
    Entity(Scene *scene, std::string entityType);
    virtual ~Entity() {};

    virtual void update() = 0;
    virtual void draw() = 0;

    const std::string type;
    bool isBroken;
};

