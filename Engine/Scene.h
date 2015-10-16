#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <list>

class Entity;
class Game;

class Scene{
private:
    std::string name;
    Game *game;
    std::unordered_map<std::string,sf::Texture&> TextureMap;
    std::list<Entity*> EntityList;

public:
    Scene(std::string name, Game *game);
    sf::Texture & getTexture(std::string name);
    void run();

private:
    void handleEvents();
    void renderWindow();
};

