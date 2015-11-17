#include "Barrier.h"


Barrier::Barrier(Scene *scene, const sf::Texture &texture) : GraphicalEntity(scene, "Barrier", texture){
    velocity = 0.0;
}

void Barrier::update() {
}

void Barrier::manageCollision(GraphicalEntity *ge) {
}
