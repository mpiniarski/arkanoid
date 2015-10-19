#include "DynamicEntity.h"

#include "Scene.h"
#include <SFML/Graphics.hpp>

using namespace std;

DynamicEntity::DynamicEntity(Scene *scene, string name) : Entity(scene, name) {
    isMovingUp = false;
    isMovingDown = false;
    isMovingRight = false;
    isMovingLeft = false;
    width = sprite.getTexture()->getSize().x;
    height = sprite.getTexture()->getSize().y;
    pos_x = 800/2 - (width / 2);
    pos_y = 530;
    velocity = 0;
    sprite.setPosition(pos_x,pos_y);
}

void DynamicEntity::makeStep() {
    if(isMovingLeft == DIRECTION::MOVING && pos_x >= 0)
        pos_x -= velocity;
    else if(isMovingRight == DIRECTION::MOVING && pos_x <= 800 - sprite.getTexture()->getSize().x)
        pos_x += velocity;
    if(isMovingUp == DIRECTION::MOVING && pos_y >= 0)
        pos_y -= velocity;
    else if(isMovingDown == DIRECTION::MOVING && pos_y <= 600 - sprite.getTexture()->getSize().y)
        pos_y += velocity;

    sprite.setPosition(pos_x, pos_y);
}

void DynamicEntity::changeDirection(int direction) {
    switch(direction) {
        case DIRECTION::LEFT:
            if(isMovingRight) isMovingRight = DIRECTION::HELD;
            isMovingLeft = DIRECTION::MOVING;
            break;
        case DIRECTION::RIGHT:
            if(isMovingLeft) isMovingLeft = DIRECTION::HELD;
            isMovingRight = DIRECTION::MOVING;
            break;
        case DIRECTION::UP:
            if(isMovingDown) isMovingDown = DIRECTION::HELD;
            isMovingUp = DIRECTION::MOVING;
            break;
        case DIRECTION::DOWN:
            if(isMovingUp) isMovingUp = DIRECTION::HELD;
            isMovingDown = DIRECTION::MOVING;
            break;
    }
}

void DynamicEntity::resetDirection(int direction) {
    if(direction == DIRECTION::LEFT) {
        isMovingLeft = DIRECTION::STOP;
        if(isMovingRight == DIRECTION::HELD) isMovingRight = DIRECTION::MOVING;
    }
    else if(direction == DIRECTION::RIGHT) {
        isMovingRight = DIRECTION::STOP;
        if(isMovingLeft == DIRECTION::HELD) isMovingLeft = DIRECTION::MOVING;
    }
}
