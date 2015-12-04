#pragma once

#include "Bonus.h"

class ColorBonus : public Bonus{
private:
    sf::Color color;

public:
    ColorBonus(Scene *scene, sf::Texture &texture, Platform *platform);
    void trigerBonus() override;
};


