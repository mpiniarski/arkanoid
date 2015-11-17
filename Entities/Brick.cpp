#include "Brick.h"


Brick::Brick(Scene *scene, const sf::Texture &texture) : GraphicalEntity(scene, "Brick", texture){
   velocity = 0.0;
}

void Brick::update() {
}

void Brick::manageCollision(GraphicalEntity *ge) {
   isBroken = true;
}