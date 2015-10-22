#pragma once

#include "Scene.h"

class DynamicEntity;

namespace DIRECTION {
    enum { UP, DOWN, LEFT, RIGHT };
    enum { STOP, MOVING, HELD };
}

class Entity {
protected:
    int isMovingRight;
    int isMovingLeft;
    int isMovingUp;
    int isMovingDown;
    double velocity;
    int acceleration;

public:
    Scene *scene;
    Entity(Scene *scene);

    virtual int update() = 0;
    virtual int draw() = 0;
};

