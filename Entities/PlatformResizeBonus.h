#pragma once

#include "Bonus.h"

class PlatformResizeBonus : public Bonus {
private:
    sf::Color color;
public:
    PlatformResizeBonus(Scene* scene, sf::Texture &texture, Platform* platform);
    void trigerBonus() override;
};
