#include <iostream>
#include <unistd.h>
#include "Scene.h"

#include "Entity.h"
#include "TextEntity.h"

using namespace std;

Scene::Scene(Game *game) {
    this->game = game;
    this->endScene = false;
    this->nextScene = NULL;
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
void Scene::removeEntity(Entity *entity) {
    EntityList.remove(entity);
}

void Scene::run(){
    sf::Clock clock;
    float timeSinceLastRender = 0.0;
    double timePerFrame =  (float)(1.0 / game->getFPS() );
    bool render = true;

    while(!endScene)
    {
        timeSinceLastRender += clock.restart().asSeconds();
        if(timeSinceLastRender >= timePerFrame) render = true;

        handleEvents();

        if(render){
            updateEntities();
            renderWindow();
//            cout<<timeSinceLastRender<<endl;
            timeSinceLastRender -= timePerFrame;
            render = false;
        }
    }
    game->launchScene(nextScene);
}

void Scene::handleEvents() {
}

void Scene::updateEntities() {
    list<Entity*>::iterator i = EntityList.begin();
    while(i!=EntityList.end()){
        Entity* entity = *i;
        if(entity->isBroken){
            i++;
            EntityList.remove(entity);
            delete entity;
            continue;
        }
        entity->update();
        i++;
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

Scene::~Scene() {
   for (auto i : EntityList){
       delete i;
   }
}

void Scene::exitScene(Scene *nextScene) {
    this->endScene = true;
    if (nextScene != NULL){
        this->nextScene = nextScene;
    }
}

void Scene::moveTextEntitiesToFront() {
    for (auto element: TextEntityMap){
        TextEntity* textEntity = (element.second);
        removeEntity(textEntity);
        addEntity(textEntity);
    }
}
