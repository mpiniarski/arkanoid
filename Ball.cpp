#include <iostream>
#include "Ball.h"
#include "GameplayScene.h"

using namespace std;

Ball::Ball(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, texture) {
    movingHorizontal = 50;
    movingVertical = 50;
    velocity = 6.0;
    this->platform = NULL;
}

Ball::Ball(Scene *scene, const sf::Texture &texture, Platform* platform) : GraphicalEntity( scene, texture) {
    movingHorizontal = 50;
    movingVertical = 50;
    velocity = 6.0;
    this->platform = platform;
}

void Ball::wallCollision() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;

    if(pos_x<=0 || pos_x+getWidth() >= scene->getWindowWidth() ) movingHorizontal *= -1;
    if(pos_y<=0 || pos_y+getHeight() >= scene->getWindowHeight() ) movingVertical *= -1;

}

void Ball::detectCollision(GraphicalEntity *ge) {

    float ballCenterWidth = this->getPosition().x + this->getWidth()/2;
    float ballCenterHeight = this->getPosition().y + this->getHeight()/2;
    float radius = this->getWidth()/2;
    float platformCenter = ge->getPosition().x + ge->getWidth()/2;
    float platformEnd = ge->getPosition().x + ge->getWidth();
    float platformStart = ge->getPosition().x;

    /** AREA 1 **/
    if((ballCenterWidth + radius/sqrt(2)) > platformStart
       && ballCenterWidth - radius/sqrt(2) < platformStart
       && ballCenterHeight + radius/sqrt(2) > ge->getPosition().y
       && ballCenterHeight - radius/sqrt(2) < ge->getPosition().y) {
        movingHorizontal *= -1;
        movingVertical *= -1;
    }
    /** AREA 2 **/
    if(ballCenterHeight + radius > ge->getPosition().y) {
        if(ballCenterWidth >= platformStart && ballCenterWidth < platformCenter) {
            movingHorizontal = (-1) * ((ballCenterWidth - platformCenter) * 100)/(platformStart - platformCenter);
            movingVertical = (-1) * sqrt((10000-(movingHorizontal*movingHorizontal)));
//            movingVertical = (-1) * ((ballCenterWidth - platformStart) * 100)/(platformCenter - platformStart);
        }
        else if(ballCenterWidth >= platformCenter && ballCenterWidth <= platformEnd) {
            movingHorizontal = ((ballCenterWidth - platformCenter) * 100)/(platformEnd - platformCenter);
            movingVertical = (-1) * sqrt((10000-(movingHorizontal*movingHorizontal)));
//            movingVertical = (-1) * ((ballCenterWidth - platformEnd) * 100)/(platformCenter - platformEnd);
        }
    }
    /** AREA 3 **/
    if((ballCenterWidth - radius/sqrt(2)) < platformEnd
            && ballCenterWidth + radius/sqrt(2)> platformEnd
            && ballCenterHeight + radius/sqrt(2) > ge->getPosition().y
            && ballCenterHeight - radius/sqrt(2)< ge->getPosition().y) {
        movingHorizontal *= -1;
        movingVertical *= -1;
    }
    /** AREA 4 **/
    if(ballCenterWidth + radius > platformStart
       && ballCenterWidth - radius < platformStart
       && ballCenterHeight > ge->getPosition().y) {
        movingHorizontal *= -1;
    }
    /** AREA 5 **/
    if(ballCenterWidth - radius < platformEnd
       && ballCenterWidth + radius > platformEnd
       && ballCenterHeight > ge->getPosition().y) {
        movingHorizontal *= -1;
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
