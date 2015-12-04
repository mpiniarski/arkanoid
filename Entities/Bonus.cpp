#include "Bonus.h"
#include "Platform.h"

using namespace std;


Bonus::Bonus(Scene *scene, sf::Texture &texture, Platform *platform) :
        GraphicalEntity(scene, "Bonus", texture )
{
    movingHorizontal = 0;
    movingVertical = 100;
    velocity = 3.0;
    setPosition(rand()%(scene->getWindowWidth()), 0);
    this->platform = platform;
}


void Bonus::update() {
    if(this->getPosition().y + (this->getHeight())  >= platform->getPosition().y) {
        if (detectCollision(platform)) {
            trigerBonus();
            this->isBroken = true;
        }
        else if (this->getPosition().y >= this->scene->getWindowHeight()){
            this->isBroken = true;
        }
    }
    makeStep();
}

bool Bonus::detectCollision(Platform *ge) {
    return ( this->getPosition().y + this->getHeight() > platform->getPosition().y
             && this->getPosition().y < platform->getPosition().y + platform->getHeight()
             && this->getPosition().x + this->getWidth() > platform->getPosition().x
             && this->getPosition().x < platform->getPosition().x + platform->getWidth() );
}

