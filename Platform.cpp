#include "Platform.h"
#include "GameplayScene.h"

using namespace std;

Platform::Platform(Scene *scene, const sf::Texture &texture) : GraphicalEntity( scene, "Platform", texture) {
    setPosition( (scene->getWindowWidth()-this->getWidth())/2.0, scene->getWindowHeight() - this->getHeight() - 10);
    velocity = 6.0;
}

void Platform::update() {
    makeStep();
}
