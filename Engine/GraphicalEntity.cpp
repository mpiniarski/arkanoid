#include "GraphicalEntity.h"

GraphicalEntity::GraphicalEntity(Scene *scene, const sf::Texture &texture) : Entity(scene), Sprite(texture)
{
    setPosition(0,0);
}

int GraphicalEntity::draw() {
    scene->drawOnWindow(*this);
    return 0;
}

void GraphicalEntity::makeStep() {
    float pos_x = getPosition().x;
    float pos_y = getPosition().y;
    if(isMovingLeft == DIRECTION::MOVING && pos_x >= 0)
        pos_x -= velocity;
    else if(isMovingRight == DIRECTION::MOVING && pos_x <= 800 - getWidth())
        pos_x += velocity;
    if(isMovingUp == DIRECTION::MOVING && pos_y >= 0)
        pos_y -= velocity;
    else if(isMovingDown == DIRECTION::MOVING && pos_y <= 600 - getHeight())
        pos_y += velocity;

    setPosition(pos_x, pos_y);
}

void GraphicalEntity::changeDirection(int direction) {
    switch(direction) {
        case DIRECTION::LEFT:
            if(isMovingRight) isMovingRight = DIRECTION::HELD;
            isMovingLeft = DIRECTION::MOVING;
            break;
        case DIRECTION::RIGHT:
            if(isMovingLeft) isMovingLeft = DIRECTION::HELD;
            isMovingRight = DIRECTION::MOVING;
            break;
        case DIRECTION::UP:
            if(isMovingDown) isMovingDown = DIRECTION::HELD;
            isMovingUp = DIRECTION::MOVING;
            break;
        case DIRECTION::DOWN:
            if(isMovingUp) isMovingUp = DIRECTION::HELD;
            isMovingDown = DIRECTION::MOVING;
            break;
    }
}

void GraphicalEntity::resetDirection(int direction) {
    if(direction == DIRECTION::LEFT) {
        isMovingLeft = DIRECTION::STOP;
        if(isMovingRight == DIRECTION::HELD) isMovingRight = DIRECTION::MOVING;
    }
    else if(direction == DIRECTION::RIGHT) {
        isMovingRight = DIRECTION::STOP;
        if(isMovingLeft == DIRECTION::HELD) isMovingLeft = DIRECTION::MOVING;
    }
}

