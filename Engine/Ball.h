#pragma once

#include "DynamicEntity.h"

class Ball : public DynamicEntity {
private:
    void wallCollision();
    void platformCollision();
public:
    Ball(Scene *scene, std::string name);
    int update();
};
