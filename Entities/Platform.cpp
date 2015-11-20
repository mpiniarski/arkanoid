#include "Platform.h"

#include "../Scenes/GameplayScene.h"

using namespace std;

Platform::Platform(Scene *scene, sf::Texture &texture) : GraphicalEntity( scene, "Platform", texture) {
    setPosition((float) ((scene->getWindowWidth() - this->getWidth()) / 2.0), scene->getWindowHeight() - this->getHeight() - 10);
    velocity = 10.0;
}

void Platform::update() {
    makeStep();
}
