#include "TextEntity.h"

using namespace std;

TextEntity::TextEntity(Scene *scene, string context, const sf::Font &font) : Entity(scene), Text(context, font) {
    setPosition(0,0);
}

int TextEntity::draw() {
    scene->drawOnWindow(*this);
    return 0;
}
