#pragma once

#include "../Engine/GraphicalEntity.h"

#include <list>

class GameplayScene;
class Platform;

class Ball : public GraphicalEntity {
private:
    std::list<GraphicalEntity*> collisionList;
    Platform* platform;

public:
    Ball(Scene *scene, const sf::Texture &texture, Platform* platform);
    ~Ball();
    void update();
    void addCollisionMaker(GraphicalEntity* ge);

private:
    void detectCollision(Platform *ge);
    void detectCollision(GraphicalEntity *ge);
    void wallCollision();
};
