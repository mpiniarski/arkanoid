#include <iostream>

#include "Brick.h"


Brick::Brick(Scene *scene, const sf::Texture &texture) : GraphicalEntity(scene, texture){
   velocity = 0.0;
}

void Brick::update() {
}

void Brick::manageCollision(GraphicalEntity *ge) {
   isBroken = true;
}
