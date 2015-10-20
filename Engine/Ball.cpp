#include "Ball.h"
#include "Scene.h"

using namespace std;

Ball::Ball(Scene *scene, string name) : DynamicEntity( scene, name ) {
    DynamicEntity::isMovingUp = DIRECTION::MOVING;
    DynamicEntity::isMovingRight = DIRECTION::MOVING;
    DynamicEntity::velocity = 4;
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

void Ball::platformCollision() {
    if((pos_y + height) > (scene->platform->pos_y)
       && (pos_y + height) < (scene->platform->pos_y + scene->platform->height)
       && (pos_x + width) > (scene->platform->pos_x)
       && (pos_x) < (scene->platform->pos_x + scene->platform->width)) {
        isMovingDown = DIRECTION::STOP;
        isMovingUp = DIRECTION::MOVING;
    }
    else if((pos_y) < (scene->platform->pos_y + scene->platform->height)
       && (pos_y) > (scene->platform->pos_y)
       && (pos_x + width) > (scene->platform->pos_x)
       && (pos_x) < (scene->platform->pos_x + scene->platform->width)) {
        isMovingUp = DIRECTION::STOP;
        isMovingDown = DIRECTION::MOVING;
    }
    else if((pos_x) < (scene->platform->pos_x + scene->platform->width)
            && (pos_x) > (scene->platform->pos_x)
            && (pos_y + height) > (scene->platform->pos_y)
            && (pos_y) < (scene->platform->pos_y + scene->platform->height)) {
        isMovingLeft = DIRECTION::STOP;
        isMovingRight = DIRECTION::MOVING;
    }
    else if((pos_x + width) > (scene->platform->pos_x)
            && (pos_x + width) < (scene->platform->pos_x + scene->platform->width)
            && (pos_y + height) > (scene->platform->pos_y)
            && (pos_y) < (scene->platform->pos_y + scene->platform->height)) {
        isMovingRight = DIRECTION::STOP;
        isMovingLeft = DIRECTION::MOVING;
    }
}

int Ball::update() {
    platformCollision();
    wallCollision();
    DynamicEntity::makeStep();
    sprite.setPosition(pos_x, pos_y);
}
