#include "GraphicalEntity.h"
#include "Scene.h"

GraphicalEntity::GraphicalEntity(Scene *scene, const sf::Texture &texture) : Entity(scene), Sprite(texture)
{
    movingUp = DIRECTION::STOP;
    movingDown = DIRECTION::STOP;
    movingRight = DIRECTION::STOP;
    movingLeft = DIRECTION::STOP;
    velocity = 0;
    setPosition(0,0);
}

void GraphicalEntity::draw() {
    scene->drawOnWindow(*this);
}

void GraphicalEntity::makeStep() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;
    if(movingLeft == DIRECTION::MOVING && pos_x >= 0)
        pos_x -= velocity;
    else if(movingRight == DIRECTION::MOVING && pos_x <= 800 - getWidth())
        pos_x += velocity;
    if(movingUp == DIRECTION::MOVING && pos_y >= 0)
        pos_y -= velocity;
    else if(movingDown == DIRECTION::MOVING && pos_y <= 600 - getHeight())
        pos_y += velocity;

    setPosition(pos_x, pos_y);
}

void GraphicalEntity::changeDirection(int direction) {
    switch(direction) {
        case DIRECTION::LEFT:
            if(movingRight) movingRight = DIRECTION::HELD;
            movingLeft = DIRECTION::MOVING;
            break;
        case DIRECTION::RIGHT:
            if(movingLeft) movingLeft = DIRECTION::HELD;
            movingRight = DIRECTION::MOVING;
            break;
        case DIRECTION::UP:
            if(movingDown) movingDown = DIRECTION::HELD;
            movingUp = DIRECTION::MOVING;
            break;
        case DIRECTION::DOWN:
            if(movingUp) movingUp = DIRECTION::HELD;
            movingDown = DIRECTION::MOVING;
            break;
    }
}

void GraphicalEntity::resetDirection(int direction) {
    if(direction == DIRECTION::LEFT) {
        movingLeft = DIRECTION::STOP;
        if(movingRight == DIRECTION::HELD) movingRight = DIRECTION::MOVING;
    }
    else if(direction == DIRECTION::RIGHT) {
        movingRight = DIRECTION::STOP;
        if(movingLeft == DIRECTION::HELD) movingLeft = DIRECTION::MOVING;
    }
}

void GraphicalEntity::update() {
    makeStep();
}

float GraphicalEntity::getWidth() {return getTexture()->getSize().x;};
float GraphicalEntity::getHeight() {return getTexture()->getSize().y;}
