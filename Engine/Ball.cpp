#include "Ball.h"

using namespace std;

Ball::Ball(Scene *scene, string name) : DynamicEntity( scene, name ) {
    DynamicEntity::isMovingUp = DIRECTION::MOVING;
    DynamicEntity::isMovingRight = DIRECTION::MOVING;
    DynamicEntity::velocity = 7;
}

int Ball::update() {
    if(isMovingLeft == DIRECTION::MOVING && pos_x <= 0) {
        isMovingLeft = DIRECTION::STOP;
        isMovingRight = DIRECTION::MOVING;
    }
    else if(isMovingRight == DIRECTION::MOVING && pos_x >= 800 - sprite.getTexture()->getSize().x) {
        isMovingRight = DIRECTION::STOP;
        isMovingLeft = DIRECTION::MOVING;
    }
    if(isMovingUp == DIRECTION::MOVING && pos_y <= 0) {
        isMovingUp = DIRECTION::STOP;
        isMovingDown = DIRECTION::MOVING;
    }
    else if(isMovingDown == DIRECTION::MOVING && pos_y >= 600 - sprite.getTexture()->getSize().y) {
        isMovingDown = DIRECTION::STOP;
        isMovingUp = DIRECTION::MOVING;
    }
    DynamicEntity::makeStep();
    sprite.setPosition(pos_x, pos_y);
}
