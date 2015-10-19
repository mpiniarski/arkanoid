#include "Scene.h"

#include "Game.h"
#include "DynamicEntity.h"
#include "Platform.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Scene::Scene(string name, Game *game) {
    this->name = name;
    this->game = game;

    resourceManager.loadTextureFromFile("texture1","res/img/hostile_shot.png");

    Platform *entity = new Platform(this,"texture1");
    platform = entity;
    EntityList.push_back(entity);

    resourceManager.loadTextureFromFile("texture2","res/img/ball.png");

    Ball *entity2 = new Ball(this,"texture2");
    ball = entity2;
    EntityList.push_back(entity2);
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
        if( event.type == sf::Event::Closed ) {
            game->Window.close();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
            game->Window.close();
        }
        else if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left ) {
            platform->changeDirection(DIRECTION::LEFT);
        }
        else if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right ) {
            platform->changeDirection(DIRECTION::RIGHT);
        }
        else if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left ) {
            platform->resetDirection(DIRECTION::LEFT);
        }
        else if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right ) {
            platform->resetDirection(DIRECTION::RIGHT);
        }
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
