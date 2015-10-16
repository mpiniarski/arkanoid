#include "Game.h"

#include <string>
#include <SFML/Graphics.hpp>


using namespace std;

Game::Game(string name):
        Window(sf::VideoMode( 800, 600 ), name/*, sf::Style::Fullscreen*/ )
{
    Window.setFramerateLimit(75);
}
