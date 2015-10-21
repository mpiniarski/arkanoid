#include "Scene.h"

#include "Game.h"
#include "DynamicEntity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Scene::Scene(string name, Game *game) {
    this->name = name;
    this->game = game;
}

void Scene::initialize() {
    uploadResources();
    createEntities();
}

void Scene::uploadResources() {
    uploadTextures();
}

void Scene::uploadTextures() {
}

void Scene::createEntities() {
}

void Scene::addEntity(Entity *entity) {
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
}

void Scene::updateEntities() {
    for( auto &i : EntityList){
        i->update();
    }
}

void Scene::renderWindow() {
    game->Window.clear( sf::Color( 30, 30, 30 ) );
    for( auto &i : EntityList){
        game->Window.draw( i->sprite );
    }
    game->Window.display();
}


