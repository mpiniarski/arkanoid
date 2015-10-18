#pragma once

#include "Entity.h"

class Scene;
namespace DIRECTION {
    enum { UP, DOWN, LEFT, RIGHT, STOP };
}

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
    void changeDirection(int direction);
    void resetDirection(int direction);
};

