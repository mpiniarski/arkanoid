#include "Scene.h"


#include "Entity.h"
#include "GraphicalEntity.h"
#include "TextEntity.h"
#include <SFML/Graphics.hpp>

#include <iostream>


using namespace std;

Scene::Scene(Game *game) {
    this->game = game;
}

void Scene::initialize() {
    uploadResources();
    createEntities();
}

void Scene::uploadResources() {
}

void Scene::createEntities() {
}

void Scene::addEntity(Entity *entity) {
    EntityList.push_back(entity);
}

void Scene::run(){
    sf::Clock clock;
    float timeSinceLastRender = 0.0;
    double timePerFrame =  (1.0 / game->getFPS() );
    cout<<timePerFrame;
    bool render = true;

    while( game->Window.isOpen() )
    {
        timeSinceLastRender += clock.restart().asSeconds();
        if(timeSinceLastRender >= timePerFrame) render = true;

        handleEvents();

        if(render){
            updateEntities();
            renderWindow();
            timeSinceLastRender -= timePerFrame;
            render = false;
        }
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
        i->draw();
    }
    game->Window.display();
}


void Scene::drawOnWindow(sf::Drawable &drawable) {
    game->Window.draw(drawable);
}


int Scene::getWindowWidth() { return game->getWindowWidth();}
int Scene::getWindowHeight() { return game->getWindowHeight();}
