#include "Platform.h"

using namespace std;

Platform::Platform(Scene *scene, string name) : DynamicEntity( scene, name ) {
    DynamicEntity::velocity = 6.0;
}

int Platform::update() {
    DynamicEntity::makeStep();
    sprite.setPosition(pos_x, pos_y);
}
