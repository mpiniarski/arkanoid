#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
    float FPS;
    sf::RenderWindow Window;
    Game(std::string name);
};

