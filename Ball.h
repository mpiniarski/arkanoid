#pragma once

#include <list>
#include "Engine/GraphicalEntity.h"

class GameplayScene;
class Platform;

class Ball : public GraphicalEntity {
private:
    std::list<GraphicalEntity*> collisionList;

public:
    Ball(Scene *scene, const sf::Texture &texture);
    void update();
    void addCollisionMaker(GraphicalEntity* ge);

private:
    void detectCollision(GraphicalEntity *ge);
    void wallCollision();
};
