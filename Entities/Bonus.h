#pragma once

#include "../Engine/GraphicalEntity.h"
#include <list>

class GameplayScene;
class Platform;

class Bonus : public GraphicalEntity{
protected:
    Platform* platform; // bonus can exist only with platform assigned to it

public:
    Bonus(Scene *scene, sf::Texture &texture, Platform* platform);
    virtual ~Bonus(){};

    void update();

private:
    bool detectCollision(Platform *ge);
    virtual void trigerBonus() = 0;
};

