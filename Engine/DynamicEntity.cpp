#include "DynamicEntity.h"

#include "Scene.h"
#include <SFML/Graphics.hpp>

using namespace std;

DynamicEntity::DynamicEntity(Scene *scene, string name) : Entity(scene, name) {
    this->scene = scene;
    width = sprite.getTexture()->getSize().x;
    height = sprite.getTexture()->getSize().y;
    pos_x = 800/2 - (width / 2);
    pos_y = 500;
    velocity = 10;
    sprite.setPosition(pos_x,pos_y);
}

int DynamicEntity::update() {
    if(isMovingUp) pos_y -= velocity;
    else if(isMovingDown) pos_y += velocity;
    if(isMovingRight) pos_x += velocity;
    else if(isMovingLeft) pos_x -= velocity;

    sprite.setPosition(pos_x, pos_y);
}

