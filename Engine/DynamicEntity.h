#pragma once

#include "Entity.h"

class Scene;

class DynamicEntity : public Entity {
protected:
    bool isMovingUp;
    bool isMovingRight;
    bool isMovingDown;
    bool isMovingLeft;
    int velocity;
    int acceleration;

public:
    Scene *scene;
    DynamicEntity(Scene *scene, std::string name);
    int update() override ;
};

