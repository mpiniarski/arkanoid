#include "GraphicalEntity.h"

GraphicalEntity::GraphicalEntity(Scene *scene, std::string entityType, const sf::Texture &texture) : Entity(scene, entityType), Sprite(texture)
{
    movingHorizontal = 0;
    movingVertical = 0;
    velocity = 0;
    setPosition(0,0);
}

void GraphicalEntity::draw() {
    scene->drawOnWindow(*this);  // needs to be defined so entity can "draw itself" on screen
}

void GraphicalEntity::update() {
    makeStep();
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

void GraphicalEntity::manageCollision(GraphicalEntity *ge) { // different in every GraphicalEntinty children-class
}

float GraphicalEntity::getWidth() {return getTextureRect().width;};
float GraphicalEntity::getHeight() {return getTextureRect().height;}

void GraphicalEntity::stretchToWindowSize() {
    setScale(scene->getWindowWidth()/getWidth(),scene->getWindowHeight()/getHeight());
}

