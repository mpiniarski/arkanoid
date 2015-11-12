#include "Entity.h"

Entity::Entity(Scene *scene, std::string entityType) :
        type(entityType)
{
    this->scene = scene;
    isBroken = false;
}

