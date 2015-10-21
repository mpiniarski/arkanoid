#include "Game.h"

#include <string>
#include <SFML/Graphics.hpp>


using namespace std;

Game::Game(string name):
        Window(sf::VideoMode( 800, 600 ), name/*, sf::Style::Fullscreen*/ )
{
    FPS = 60.0;
    Window.setFramerateLimit(75);
    Window.setVerticalSyncEnabled(true);
}
