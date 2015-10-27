#include "Ball.h"

using namespace std;

Ball::Ball(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, texture) {
    movingUp = DIRECTION::MOVING;
    movingRight = DIRECTION::MOVING;
    velocity = 2.5;
}

void Ball::wallCollision() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;

    if(movingLeft == DIRECTION::MOVING && pos_x <= 0) {
        movingLeft = DIRECTION::STOP;
        movingRight = DIRECTION::MOVING;
    }
    else if(movingRight == DIRECTION::MOVING && pos_x >= 800 - getWidth()) {
        movingRight = DIRECTION::STOP;
        movingLeft = DIRECTION::MOVING;
    }
    if(movingUp == DIRECTION::MOVING && pos_y <= 0) {
        movingUp = DIRECTION::STOP;
        movingDown = DIRECTION::MOVING;
    }
    else if(movingDown == DIRECTION::MOVING && pos_y >= 600 - getHeight()) {
        movingDown = DIRECTION::STOP;
        movingUp = DIRECTION::MOVING;
    }
}

void Ball::detectCollision(GraphicalEntity *ge) {
    if((getPosition().y + getHeight()) > (  ge->getPosition().x )
       && (getPosition().y + getHeight()) < (ge->getPosition().y + ge->getHeight())
       && (getPosition().x + getWidth()) > (ge->getPosition().x)
       && (getPosition().x) < (ge->getPosition().x + ge->getWidth())) {
        movingDown = DIRECTION::STOP;
        movingUp = DIRECTION::MOVING;
    }
    else if((getPosition().y) < (ge->getPosition().y + ge->getHeight())
       && (getPosition().y) > (ge->getPosition().y)
       && (getPosition().x + getWidth()) > (ge->getPosition().x)
       && (getPosition().x) < (ge->getPosition().x + ge->getWidth())) {
        movingUp = DIRECTION::STOP;
        movingDown = DIRECTION::MOVING;
    }
    else if((getPosition().x) < (ge->getPosition().x + ge->getWidth())
            && (getPosition().x) > (ge->getPosition().x)
            && (getPosition().y + getHeight()) > (ge->getPosition().y)
            && (getPosition().y) < (ge->getPosition().y + ge->getHeight())) {
        movingLeft = DIRECTION::STOP;
        movingRight = DIRECTION::MOVING;
    }
    else if((getPosition().x + getWidth()) > (ge->getPosition().x)
            && (getPosition().x + getWidth()) < (ge->getPosition().x + ge->getWidth())
            && (getPosition().y + getHeight()) > (ge->getPosition().y)
            && (getPosition().y) < (ge->getPosition().y + ge->getHeight())) {
        movingRight = DIRECTION::STOP;
        movingLeft = DIRECTION::MOVING;
    }
}

void Ball::update() {
    for(auto &i : collisionList){
        detectCollision(i);
    }
    wallCollision();
    makeStep();
}

void Ball::addCollisionMaker(GraphicalEntity *ge) {
    collisionList.push_back(ge);
}
