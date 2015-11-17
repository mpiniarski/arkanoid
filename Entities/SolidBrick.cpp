#include "SolidBrick.h"


SolidBrick::SolidBrick(Scene *scene, const sf::Texture &texture) : GraphicalEntity(scene, "SolidBrick", texture){
    velocity = 0.0;
    lives = 3;
    this->setTextureRect(sf::Rect<int>(0,0,this->getWidth(),this->getHeight()/3));
}

void SolidBrick::update() {
}

void SolidBrick::manageCollision(GraphicalEntity *ge) {
    lives--;
    if(lives > 0) {
        switch(lives) {
            case 2:
                setTextureRect(sf::Rect<int>(0,this->getHeight(),this->getWidth(),this->getHeight()));
                break;
            case 1:
                setTextureRect(sf::Rect<int>(0,2*this->getHeight(),this->getWidth(),this->getHeight()));
                break;
        }
    }
    else { isBroken = true; }
}
