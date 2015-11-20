#pragma once

#include "Scene.h"

class Entity{ // abstrackt class
public:
    Scene *scene;
    bool isBroken;

public:
    Entity(Scene *scene, std::string entityType);
    virtual ~Entity() {};

    virtual void update() = 0; // each entity type must update itself in certain way, different in every entinty type
    virtual void draw() = 0;

    const std::string type;
};

