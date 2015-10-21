#pragma once

#include "Entity.h"

class Scene;
namespace DIRECTION {
    enum { UP, DOWN, LEFT, RIGHT };
    enum { STOP, MOVING, HELD };
}

class DynamicEntity : public Entity {
protected:
    int isMovingRight;
    int isMovingLeft;
    int isMovingUp;
    int isMovingDown;
    double velocity;
    int acceleration;

public:
    DynamicEntity(Scene *scene, std::string name);
    //int update() ;
    void makeStep();
    void changeDirection(int direction);
    void resetDirection(int direction);
};

