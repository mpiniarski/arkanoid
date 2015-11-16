#include <iostream>
#include "Ball.h"
#include "GameplayScene.h"
#include "MenuScene.h"

#include "Platform.h"

using namespace std;


Ball::Ball(Scene *scene, const sf::Texture &texture, Platform* platform) : GraphicalEntity( scene, "Ball", texture) {
    movingHorizontal = (float) ((-1) * sqrt(10000 / 2));
    movingVertical = (float) sqrt(10000 / 2);
    setPosition(platform->getPosition().x, platform->getPosition().y - this->getHeight() );
    movingHorizontal = 70;
    movingVertical = 70;
    velocity = 6.0;
    this->platform = platform;
}

void Ball::wallCollision() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;

    if(pos_x<=0 || pos_x+getWidth() >= scene->getWindowWidth() ) movingHorizontal *= -1;
    if(pos_y<=0) movingVertical *= -1;
    if(pos_y >= scene->getWindowHeight()) {
        scene->exitScene();
    }
}

void Ball::detectCollision(Platform *ge) {

    float edge = 80;        //max MovingHorizontal
    float ballCenterWidth = this->getPosition().x + this->getWidth()/2;
    float ballCenterHeight = this->getPosition().y + this->getHeight()/2;
    float radius = this->getWidth()/2;
    float platformCenter = ge->getPosition().x + ge->getWidth()/2;
    float platformEnd = ge->getPosition().x + ge->getWidth();
    float platformStart = ge->getPosition().x;

    if(ballCenterHeight <= ge->getPosition().y) {
        /** AREA 1 **/
        if(ballCenterWidth < platformStart) {
            if((ballCenterWidth + radius/sqrt(2)) >= platformStart
               && ballCenterHeight + radius/sqrt(2) >= ge->getPosition().y) {
                movingHorizontal = -edge;
                movingVertical = (-1) * sqrt((10000-(abs(movingHorizontal*movingHorizontal))));
            }
        }
        /** AREA 2 **/
        else if(ballCenterWidth >= platformStart && ballCenterWidth <= platformEnd) {
            if(ballCenterHeight + radius >= ge->getPosition().y) {
                if(ballCenterWidth < platformCenter) {
                    movingHorizontal = (-1) * ((ballCenterWidth - platformCenter) * edge)/(platformStart - platformCenter);
                    movingVertical = (-1) * sqrt((10000-(abs(movingHorizontal*movingHorizontal))));
                }
                else if(ballCenterWidth <= platformEnd) {
                    movingHorizontal = ((ballCenterWidth - platformCenter) * edge)/(platformEnd - platformCenter);
                    movingVertical = (-1) * sqrt((10000-(abs(movingHorizontal*movingHorizontal))));
                }
            }
        }
        /** AREA 3 **/
        else {
            if((ballCenterWidth - radius/sqrt(2)) <= platformEnd
               && ballCenterHeight + radius/sqrt(2) >= ge->getPosition().y) {
                movingHorizontal = edge;
                movingVertical = (-1) * sqrt((10000-(abs(movingHorizontal*movingHorizontal))));
            }
        }
    }
    else if(ballCenterHeight < scene->getWindowHeight()){
        /** AREA 4 **/
        if(ballCenterWidth <= platformStart) {
            if(ballCenterWidth + radius >= platformStart) {
                movingHorizontal = abs(movingHorizontal) * -1;
            }
        }
        /** AREA 5 **/
        else if(ballCenterWidth >= platformEnd) {
            if(ballCenterWidth - radius <= platformEnd) {
                movingHorizontal = abs(movingHorizontal);
            }
        }
    }
}

void Ball::detectCollision(GraphicalEntity *ge) {

    float ballCenterWidth = this->getPosition().x + this->getWidth()/2;
    float ballCenterHeight = this->getPosition().y + this->getHeight()/2;
    float radius = this->getWidth()/2;
    float geCenter = ge->getPosition().x + ge->getWidth()/2;
    float geEnd = ge->getPosition().x + ge->getWidth();
    float geStart = ge->getPosition().x;

    if(ballCenterHeight <= ge->getPosition().y) {
        /** AREA 1 **/
        if(ballCenterWidth < geStart) {
            if((ballCenterWidth + radius/sqrt(2)) >= geStart
               && ballCenterHeight + radius/sqrt(2) >= ge->getPosition().y) {
                movingHorizontal = abs(movingHorizontal) * -1;
                movingVertical = abs(movingVertical) * -1;
                ge->manageCollision(this);
            }
        }
        /** AREA 2 **/
        else if(ballCenterWidth >= geStart && ballCenterWidth <= geEnd) {
            if(ballCenterHeight + radius >= ge->getPosition().y) {
                movingVertical = abs(movingVertical) * -1;
                ge->manageCollision(this);
            }
        }
        /** AREA 3 **/
        else {
            if((ballCenterWidth - radius/sqrt(2)) <= geEnd
               && ballCenterHeight + radius/sqrt(2) >= ge->getPosition().y) {
                movingHorizontal = abs(movingHorizontal);
                movingVertical = abs(movingVertical) * -1;
                ge->manageCollision(this);
            }
        }
    }
    else if(ballCenterHeight > ge->getPosition().y && ballCenterHeight < ge->getPosition().y + ge->getHeight()) {
        /** AREA 4 **/
        if(ballCenterWidth <= geStart) {
            if(ballCenterWidth + radius >= geStart) {
                movingHorizontal = abs(movingHorizontal) * -1;
                ge->manageCollision(this);
            }
        }
        /** AREA 5 **/
        else if(ballCenterWidth >= geEnd) {
            if(ballCenterWidth - radius <= geEnd) {
                movingHorizontal = abs(movingHorizontal);
                ge->manageCollision(this);
            }
        }
    }
    else {
        /** AREA 6 **/
        if(ballCenterWidth < geStart) {
            if((ballCenterWidth + radius/sqrt(2)) >= geStart
               && ballCenterHeight - radius/sqrt(2) <= ge->getPosition().y + ge->getHeight()) {
                movingHorizontal = abs(movingHorizontal) * -1;
                movingVertical = abs(movingVertical);
                ge->manageCollision(this);
            }
        }
        /** AREA 7 **/
        else if(ballCenterWidth >= geStart && ballCenterWidth <= geEnd) {
            if(ballCenterHeight - radius < ge->getPosition().y + ge->getHeight()) {
                movingVertical = abs(movingVertical);
                ge->manageCollision(this);
            }
        }
        /** AREA 8 **/
        else {
            if ((ballCenterWidth - radius / sqrt(2)) <= geEnd
                && ballCenterHeight - radius / sqrt(2) <= ge->getPosition().y + ge->getHeight()) {
                movingHorizontal = abs(movingHorizontal);
                movingVertical = abs(movingVertical);
                ge->manageCollision(this);
            }
        }
    }
}

void Ball::update() {
    if(this->getPosition().y + (this->getHeight())  >= platform->getPosition().y) {
        detectCollision(platform);
    }
    else {
        list<GraphicalEntity*>::iterator i;
        for(i=collisionList.begin(); i != collisionList.end(); i++){
            GraphicalEntity* entity = *i;
            detectCollision(entity);
            if(entity->isBroken){
                i++;
                collisionList.remove(entity);
            }
        }
    }
    wallCollision();
    makeStep();
}

void Ball::addCollisionMaker(GraphicalEntity *ge) {
    collisionList.push_back(ge);
}

Ball::~Ball() {
    collisionList.clear();
}
