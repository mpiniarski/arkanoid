#include "Ball.h"

using namespace std;

Ball::Ball(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, texture) {
    movingHorizontal = -100;
    movingVertical = 100;
    velocity = 2.5;
}

void Ball::wallCollision() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;

    if(pos_x<=0 || pos_x+getWidth() >= scene->getWindowWidth() ) movingHorizontal *= -1;
    if(pos_y<=0 || pos_y+getHeight() >= scene->getWindowHeight() ) movingVertical *= -1;

}

void Ball::detectCollision(GraphicalEntity *ge) {
    if((getPosition().y + getHeight()) > (  ge->getPosition().y )
       && (getPosition().y + getHeight()) < (ge->getPosition().y + ge->getHeight())
       && (getPosition().x + getWidth()) > (ge->getPosition().x)
       && (getPosition().x) < (ge->getPosition().x + ge->getWidth())) {
        movingVertical = -100;
    }
    else if((getPosition().y) < (ge->getPosition().y + ge->getHeight())
       && (getPosition().y) > (ge->getPosition().y)
       && (getPosition().x + getWidth()) > (ge->getPosition().x)
       && (getPosition().x) < (ge->getPosition().x + ge->getWidth())) {
        movingVertical = 100;
    }
    else if((getPosition().x) < (ge->getPosition().x + ge->getWidth())
            && (getPosition().x) > (ge->getPosition().x)
            && (getPosition().y + getHeight()) > (ge->getPosition().y)
            && (getPosition().y) < (ge->getPosition().y + ge->getHeight())) {
        movingHorizontal = 100;
    }
    else if((getPosition().x + getWidth()) > (ge->getPosition().x)
            && (getPosition().x + getWidth()) < (ge->getPosition().x + ge->getWidth())
            && (getPosition().y + getHeight()) > (ge->getPosition().y)
            && (getPosition().y) < (ge->getPosition().y + ge->getHeight())) {
        movingHorizontal = -100;
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
