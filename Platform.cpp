#include "Platform.h"
#include "GameplayScene.h"

using namespace std;

Platform::Platform(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, "Platform", texture) {
    setPosition(800/2, 600 - this->getHeight());
    velocity = 6.0;
}

void Platform::update() {
    makeStep();
}
