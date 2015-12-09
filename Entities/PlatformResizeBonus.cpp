#include "PlatformResizeBonus.h"
#include "Platform.h"

PlatformResizeBonus::PlatformResizeBonus(Scene *scene, sf::Texture &texture, Platform *platform) :
        Bonus(scene, texture, platform),
        color(111,0,0,111) {
    setColor(color);
}


void PlatformResizeBonus::trigerBonus() {
    bool scale = rand()%3;
    switch(scale) {
        case 0:
            platform->setScale(0.75, 1);
            break;
        case 1:
            platform->setScale(1, 1);
            break;
        case 2:
            platform->setScale(1.25, 1);
            break;
        default:
            platform->setScale(1, 1);
            break;
    }
}
