#include <bits/unordered_map.h>
#include "Entity.h"
#include "Scene.h"


Entity::Entity(Scene *scene) {
    this->scene = scene;
    sprite = NULL;
}

Entity::Entity(Scene *scene, string name) {
    this->scene = scene;

    sf::Sprite *sprite = new sf::Sprite( scene->getTexture("texture1") );
    sprite->setPosition(50,50);
}
