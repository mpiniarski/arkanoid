#include "Scene.h"

#include "Game.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Scene::Scene(string name, Game *game) {
    this->name = name;
    this->game = game;

    resourceManager.loadTextureFromFile("texture1","res/img/hostile_shot.png");

    Entity *entity = new Entity(this,"texture1");
    EntityList.push_back(entity);
}

void Scene::run(){
    while( game->Window.isOpen() )
    {
        handleEvents();
        renderWindow();
    }
}

void Scene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) )
    {
        if( event.type == sf::Event::Closed )
            game->Window.close();
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
            game->Window.close();

    }
}

void Scene::renderWindow() {
    game->Window.clear( sf::Color( 0, 0, 0 ) );

    game->Window.draw(EntityList.front()->sprite);

//    for( list<Entity*>::iterator i = EntityList.begin(); i!=EntityList.end(); i++){
//        game->Window.draw( **i );
//    }

    game->Window.display();
}

