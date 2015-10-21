#include "Ball.h"

using namespace std;

Ball::Ball(GameplayScene *scene, string name) : DynamicEntity( scene, name ) {
    isMovingUp = DIRECTION::MOVING;
    isMovingRight = DIRECTION::MOVING;
    velocity = 2.5;
}

void Ball::wallCollision() {
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
}

void Ball::platformCollision(Entity *platform) {
    if((pos_y + height) > (  platform->pos_x )
       && (pos_y + height) < (platform->pos_y + platform->height)
       && (pos_x + width) > (platform->pos_x)
       && (pos_x) < (platform->pos_x + platform->width)) {
        isMovingDown = DIRECTION::STOP;
        isMovingUp = DIRECTION::MOVING;
    }
    else if((pos_y) < (platform->pos_y + platform->height)
       && (pos_y) > (platform->pos_y)
       && (pos_x + width) > (platform->pos_x)
       && (pos_x) < (platform->pos_x + platform->width)) {
        isMovingUp = DIRECTION::STOP;
        isMovingDown = DIRECTION::MOVING;
    }
    else if((pos_x) < (platform->pos_x + platform->width)
            && (pos_x) > (platform->pos_x)
            && (pos_y + height) > (platform->pos_y)
            && (pos_y) < (platform->pos_y + platform->height)) {
        isMovingLeft = DIRECTION::STOP;
        isMovingRight = DIRECTION::MOVING;
    }
    else if((pos_x + width) > (platform->pos_x)
            && (pos_x + width) < (platform->pos_x + platform->width)
            && (pos_y + height) > (platform->pos_y)
            && (pos_y) < (platform->pos_y + platform->height)) {
        isMovingRight = DIRECTION::STOP;
        isMovingLeft = DIRECTION::MOVING;
    }
}

int Ball::update() {
    platformCollision(colisionMaker);
    wallCollision();
    DynamicEntity::makeStep();
    sprite.setPosition(pos_x, pos_y);
}
