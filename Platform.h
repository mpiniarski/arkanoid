#pragma once

#include "Engine/DynamicEntity.h"

class Platform : public DynamicEntity {

public:
    Platform(Scene *scene, std::string name);
    int update();
};

