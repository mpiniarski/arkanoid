#include "ColorBonus.h"
#include "Platform.h"

ColorBonus::ColorBonus(Scene *scene, sf::Texture &texture, Platform *platform) :
        Bonus(scene, texture, platform),
        color(rand()%256,rand()%256,rand()%256,255)
{
    setColor(color);
}


void ColorBonus::trigerBonus() {
    platform->setColor(color);


}
