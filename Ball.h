#pragma once

#include "Engine/DynamicEntity.h"
#include "GameplayScene.h"


class Ball : public DynamicEntity {
private:
    void wallCollision();
    void platformCollision(Entity *platform);
public:
    Ball(GameplayScene *scene, std::string name);
    int update();

    Entity* colisionMaker;

};
