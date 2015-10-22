#pragma once

#include "Engine/GraphicalEntity.h"

class GameplayScene;
class Platform;

class Ball : public GraphicalEntity {
private:
    void wallCollision();
    void platformCollision(GraphicalEntity *platform);
public:
    Ball(GameplayScene *scene, const sf::Texture &texture);
    int update();

    GraphicalEntity* colisionMaker;

};
