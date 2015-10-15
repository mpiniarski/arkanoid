#pragma once

#include <string>
#include "Game.h"
#include <unordered_map>
#include <list>

using namespace std;


class Scene{
private:
    string name;
    Game *game;
    unordered_map<string,sf::Texture*> TextureMap;

    list<sf::Sprite*> SpriteList;
public:
    Scene(string name, Game *game);
    void run();

private:
    void handleEvents();
    void renderWindow();
};

