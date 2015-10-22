#include "Ball.h"

using namespace std;

Ball::Ball(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, texture) {
    isMovingUp = DIRECTION::MOVING;
    isMovingRight = DIRECTION::MOVING;
    velocity = 2.5;
}

void Ball::wallCollision() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;

    if(isMovingLeft == DIRECTION::MOVING && pos_x <= 0) {
        isMovingLeft = DIRECTION::STOP;
        isMovingRight = DIRECTION::MOVING;
    }
    else if(isMovingRight == DIRECTION::MOVING && pos_x >= 800 - getWidth()) {
        isMovingRight = DIRECTION::STOP;
        isMovingLeft = DIRECTION::MOVING;
    }
    if(isMovingUp == DIRECTION::MOVING && pos_y <= 0) {
        isMovingUp = DIRECTION::STOP;
        isMovingDown = DIRECTION::MOVING;
    }
    else if(isMovingDown == DIRECTION::MOVING && pos_y >= 600 - getHeight()) {
        isMovingDown = DIRECTION::STOP;
        isMovingUp = DIRECTION::MOVING;
    }
}

void Ball::platformCollision(GraphicalEntity *platform) {
    if((getPosition().y + getHeight()) > (  platform->getPosition().x )
       && (getPosition().y + getHeight()) < (platform->getPosition().y + platform->getHeight())
       && (getPosition().x + getWidth()) > (platform->getPosition().x)
       && (getPosition().x) < (platform->getPosition().x + platform->getWidth())) {
        isMovingDown = DIRECTION::STOP;
        isMovingUp = DIRECTION::MOVING;
    }
    else if((getPosition().y) < (platform->getPosition().y + platform->getHeight())
       && (getPosition().y) > (platform->getPosition().y)
       && (getPosition().x + getWidth()) > (platform->getPosition().x)
       && (getPosition().x) < (platform->getPosition().x + platform->getWidth())) {
        isMovingUp = DIRECTION::STOP;
        isMovingDown = DIRECTION::MOVING;
    }
    else if((getPosition().x) < (platform->getPosition().x + platform->getWidth())
            && (getPosition().x) > (platform->getPosition().x)
            && (getPosition().y + getHeight()) > (platform->getPosition().y)
            && (getPosition().y) < (platform->getPosition().y + platform->getHeight())) {
        isMovingLeft = DIRECTION::STOP;
        isMovingRight = DIRECTION::MOVING;
    }
    else if((getPosition().x + getWidth()) > (platform->getPosition().x)
            && (getPosition().x + getWidth()) < (platform->getPosition().x + platform->getWidth())
            && (getPosition().y + getHeight()) > (platform->getPosition().y)
            && (getPosition().y) < (platform->getPosition().y + platform->getHeight())) {
        isMovingRight = DIRECTION::STOP;
        isMovingLeft = DIRECTION::MOVING;
    }
}

int Ball::update() {
    platformCollision(colisionMaker);
    wallCollision();
    makeStep();
}

