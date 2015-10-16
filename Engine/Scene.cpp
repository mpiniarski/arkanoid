#include "Scene.h"

#include "Game.h"
#include "DynamicEntity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Scene::Scene(string name, Game *game) {
    this->name = name;
    this->game = game;

    resourceManager.loadTextureFromFile("texture1","res/img/hostile_shot.png");

    DynamicEntity *entity = new DynamicEntity(this,"texture1");
    platform = entity;
    EntityList.push_back(entity);
}

void Scene::run(){
    while( game->Window.isOpen() )
    {
        handleEvents();
        updateEntities();
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

    for( auto &i : EntityList){
        game->Window.draw( i->sprite );
    }

    game->Window.display();
}

void Scene::updateEntities() {

    for( auto &i : EntityList){
        i->update();
    }

}
