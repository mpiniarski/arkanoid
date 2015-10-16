#pragma once

#include <string>
#include "Game.h"
#include <unordered_map>
#include <list>

using namespace std;


class Entity;

class Scene{
private:
    string name;
    Game *game;
    unordered_map<string,sf::Texture*> TextureMap;

    list<Entity*> EntityList;

public:
    Scene(string name, Game *game);
    sf::Texture* getTexture(string name);
    void run();

private:
    void handleEvents();
    void renderWindow();
};

