#pragma once

#include "../Engine/GraphicalEntity.h"

#include <list>

class GameplayScene;
class Platform;

class Ball : public GraphicalEntity {
private:
    float edge = 80;        //max MovingHorizontal
    std::list<GraphicalEntity*> collisionList; // list of GraphicalEntities with which Ball collides
    Platform* platform; // ball can exist only with platform assigned to it

public:
    Ball(Scene *scene, sf::Texture &texture, Platform* platform);
    ~Ball();

    void update();
    void addCollisionMaker(GraphicalEntity* ge);

private:
    void detectCollision(Platform *ge);
    void detectCollision(GraphicalEntity *ge);
    void wallCollision();
};
