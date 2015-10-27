#include "Platform.h"
#include "GameplayScene.h"

using namespace std;

Platform::Platform(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, texture) {
    setPosition(800/2, 600/2);
    velocity = 6.0;
}

void Platform::update() {
    makeStep();
}
