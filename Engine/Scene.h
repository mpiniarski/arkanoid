#pragma once

#include <string>
#include "Game.h"

using namespace std;


class Scene{
private:
    string name;
    Game *game;
public:
    Scene(string name, Game *game);
    void run();
};

