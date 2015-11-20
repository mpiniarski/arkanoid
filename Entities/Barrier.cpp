#include "Barrier.h"


Barrier::Barrier(Scene *scene, const sf::Texture &texture) : GraphicalEntity(scene, "Barrier", texture){
    velocity = 0.0;
}

void Barrier::update() { //actually doing nothing
}

void Barrier::manageCollision(GraphicalEntity *ge) { //actually doing nothing
}
