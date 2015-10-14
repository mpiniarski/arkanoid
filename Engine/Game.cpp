//
// Created by joanna on 14.10.15.
//

#include <string>
#include <SFML/Graphics.hpp>

#include "Game.h"

Game::Game(string name) {
    Window.create(sf::VideoMode( 800, 600 ), name/*, sf::Style::Fullscreen*/ );
    Window.setFramerateLimit(75);
}

