#pragma once

#include "DynamicEntity.h"

class Ball : public DynamicEntity {
t 
public:
    Ball(Scene *scene, std::string name);
    int update();
};
