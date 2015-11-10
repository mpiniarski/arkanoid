#include "GraphicalEntity.h"
#include "Scene.h"
#include "../MenuScene.h"

GraphicalEntity::GraphicalEntity(Scene *scene, const sf::Texture &texture) : Entity(scene), Sprite(texture)
{
    movingHorizontal = 0;
    movingVertical = 0;
    velocity = 0;
    setPosition(0,0);
}

void GraphicalEntity::draw() {
    scene->drawOnWindow(*this);
}

void GraphicalEntity::makeStep() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;
    pos_x += movingHorizontal/100 * velocity;
    pos_y += movingVertical/100 * velocity;

    if (pos_x<=0) pos_x = 0;
    else if (pos_x+getWidth() >= scene->getWindowWidth()) pos_x = scene->getWindowWidth() - getWidth();
    if (pos_y<=0) pos_y = 0;
    else if (pos_y >= scene->getWindowHeight()) pos_y = scene->getWindowHeight();

    setPosition(pos_x, pos_y);
}

void GraphicalEntity::changeDirection(int direction) {
    switch(direction) {
        case DIRECTION::LEFT:
            movingHorizontal = -100;
            break;
        case DIRECTION::RIGHT:
            movingHorizontal = 100;
            break;
        case DIRECTION::UP:
            movingVertical = -100;
            break;
        case DIRECTION::DOWN:
            movingVertical = 100;
            break;
    }
}

void GraphicalEntity::resetDirection(int direction) {
    switch(direction) {
        case DIRECTION::LEFT:
            movingHorizontal = 0;
            break;
        case DIRECTION::RIGHT:
            movingHorizontal = 0;
            break;
        case DIRECTION::UP:
            movingVertical = 0;
            break;
        case DIRECTION::DOWN:
            movingVertical = 0;
            break;
    }
}

void GraphicalEntity::update() {
    makeStep();
}

float GraphicalEntity::getWidth() {return getTexture()->getSize().x;};
float GraphicalEntity::getHeight() {return getTexture()->getSize().y;}
