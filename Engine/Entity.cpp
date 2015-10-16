#include "Entity.h"

#include "Scene.h"

using namespace std;

Entity::Entity(Scene *scene)
{
    this->scene = scene;
}

Entity::Entity(Scene *scene, string name):
    sprite(scene->getTexture(name))
{
    this->scene = scene;

    sprite.setPosition(50,50);
}
