#include "Scene.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

Scene::Scene(string name, Game *game) {
    this->name = name;
    this->game = game;
}

void Scene::run(){
    while( game->Window.isOpen() )
    {
        sf::Event event;
        while( game->Window.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                game->Window.close();
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                game->Window.close();

        }
        game->Window.clear( sf::Color( 111, 0, 0 ) );
        game->Window.display();
    }
}

