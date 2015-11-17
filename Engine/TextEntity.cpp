#include "TextEntity.h"


using namespace std;

TextEntity::TextEntity(Scene *scene, string content, const sf::Font &font) : Entity(scene, "Text"), Text(content, font) {
    setPosition(0,0);
}

void TextEntity::draw() {
    scene->drawOnWindow(*this);
}
