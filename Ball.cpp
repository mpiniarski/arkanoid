#include <iostream>
#include "Ball.h"
#include "GameplayScene.h"

using namespace std;

Ball::Ball(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, texture) {
    movingHorizontal = -100;
    movingVertical = 100;
    velocity = 3.0;
    this->platform = NULL;
}

Ball::Ball(Scene *scene, const sf::Texture &texture, Platform* platform) : GraphicalEntity( scene, texture) {
    movingHorizontal = -100;
    movingVertical = 100;
    velocity = 3.0;
    this->platform = platform;
}

void Ball::wallCollision() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;

    if(pos_x<=0 || pos_x+getWidth() >= scene->getWindowWidth() ) movingHorizontal *= -1;
    if(pos_y<=0 || pos_y+getHeight() >= scene->getWindowHeight() ) movingVertical *= -1;

}

void Ball::detectCollision(GraphicalEntity *ge) {

    float ballCenter = this->getPosition().x + this->getWidth()/2;
    float platformCenter = ge->getPosition().x + ge->getWidth()/2;
    float platformEnd = ge->getPosition().x + ge->getWidth();
    float platformStart = ge->getPosition().x;

    if(this->getPosition().y + this->getHeight() > ge->getPosition().y) {
        if(ballCenter >= platformStart && ballCenter < platformCenter) {
            movingHorizontal = (-1) * ((ballCenter - platformCenter) * 100)/(platformStart - platformCenter);
            movingVertical = (-1) * sqrt((20000-(movingHorizontal*movingHorizontal)));
//            movingVertical = (-1) * ((ballCenter - platformStart) * 100)/(platformCenter - platformStart);
        }
        else if(ballCenter >= platformCenter && ballCenter <= platformEnd) {
            movingHorizontal = ((ballCenter - platformCenter) * 100)/(platformEnd - platformCenter);
            movingVertical = (-1) * sqrt((20000-(movingHorizontal*movingHorizontal)));
//            movingVertical = (-1) * ((ballCenter - platformEnd) * 100)/(platformCenter - platformEnd);
        }
    }
}

void Ball::update() {
    if(platform != NULL) {
        if(this->getPosition().y + (this->getHeight()/2)  <= platform->getPosition().y + (this->getHeight()/2)) {
            detectCollision(platform);
        }
    }
//    for(auto &i : collisionList){
//        detectCollision(i);
//    }
    wallCollision();
    makeStep();
}

void Ball::addCollisionMaker(GraphicalEntity *ge) {
    collisionList.push_back(ge);
}
