#include "DynamicEntity.h"

#include "Scene.h"
#include <SFML/Graphics.hpp>

using namespace std;

DynamicEntity::DynamicEntity(Scene *scene, string name) : Entity(scene, name) {
    this->scene = scene;
    isMovingDown = false;
    isMovingUp = false;
    isMovingRight = false;
    isMovingLeft = false;
    width = sprite.getTexture()->getSize().x;
    height = sprite.getTexture()->getSize().y;
    pos_x = 800/2 - (width / 2);
    pos_y = 500;
    velocity = 10;
    sprite.setPosition(pos_x,pos_y);
}

int DynamicEntity::update() {
    if(isMovingUp && pos_y >= 0) pos_y -= velocity;
    else if(isMovingDown && pos_y <= 600 - sprite.getTexture()->getSize().x) pos_y += velocity;
    if(isMovingLeft && pos_x >= 0) pos_x -= velocity;
    else if(isMovingRight && pos_x <= 800 - sprite.getTexture()->getSize().x) pos_x += velocity;

    sprite.setPosition(pos_x, pos_y);
}

void DynamicEntity::changeDirection(int direction) {
    switch(direction) {
        case DIRECTION::LEFT:
            if(isMovingRight) isMovingRight = 0;
            isMovingLeft = 1;
            break;
        case DIRECTION::RIGHT:
            if(isMovingLeft) isMovingLeft = 0;
            isMovingRight = 1;
            break;
        case DIRECTION::STOP:
            isMovingLeft = 0;
            isMovingRight = 0;
    }
}

void DynamicEntity::resetDirection(int direction) {
    if(direction == DIRECTION::LEFT) isMovingLeft = 0;
    else if(direction == DIRECTION::RIGHT) isMovingRight = 0;
}

