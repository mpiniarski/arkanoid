#pragma once

#include "Scene.h"

class Entity{
protected:
    Scene *scene;
public:
    Entity(Scene *scene);
    virtual void update() = 0;
    virtual void draw() = 0;
};

