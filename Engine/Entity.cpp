#include "Entity.h"
#include "Scene.h"

using namespace std;

Entity::Entity(Scene *scene)
{
    this->scene = scene;

    isMovingUp = false;
    isMovingDown = false;
    isMovingRight = false;
    isMovingLeft = false;

    velocity = 0;
    acceleration = 0;
}

