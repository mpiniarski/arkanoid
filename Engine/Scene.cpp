#include <iostream>
#include <unistd.h>
#include "Scene.h"

#include "Entity.h"
#include "TextEntity.h"

using namespace std;

Scene::Scene(Game *game) {
    // <- initialize() needs to be called here in constructors of other scenes
    this->game = game;
    this->endScene = false;
    this->nextScene = NULL;
}

void Scene::initialize() {
    uploadResources();
    createEntities();
}

void Scene::uploadResources() { // different in every scene
}

void Scene::createEntities() { // different in every scene
}

void Scene::run(){
    sf::Clock clock;
    float timeSinceLastRender = 0.0;
    double timePerFrame =  (float)(1.0 / game->getFPS() );

    clock.restart();
    while(!endScene)
    {
        handleEvents(); // <- important

        timeSinceLastRender = clock.restart().asSeconds();
        if(timeSinceLastRender <  timePerFrame){
            usleep((__useconds_t) (int)((timePerFrame - timeSinceLastRender) * 1000000)); // CPU works less, not sure if working
        }

        updateEntities(); // <- important
        renderWindow(); // <- important
    }
    game->launchScene(nextScene); // <- important
}

void Scene::handleEvents() { // different in every scene
}

void Scene::updateEntities() { // updates every entity in scene, destroys broken ones
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

void Scene::renderWindow() {  // draws every entity in scene
    game->Window.clear( sf::Color( 30, 30, 30 ) );
    for( auto &i : EntityList){
        i->draw();
    }
    game->Window.display();
}

void Scene::drawOnWindow(sf::Drawable &drawable) {  // this method is needed so each entity can use draw() funcion (can "draw itself" on screen)
    game->Window.draw(drawable);                    // couse Entity itself isnt drawable, but its childrens, who define "draw()" are,
}

void Scene::exitScene(Scene *nextScene) { // manages exiting scenes, loading next scenes
    this->endScene = true;
    if (nextScene != NULL){
        this->nextScene = nextScene;
    }
}


void Scene::addEntity(Entity *entity) {
    EntityList.push_back(entity);
}
void Scene::removeEntity(Entity *entity) {
    EntityList.remove(entity);
}

void Scene::moveTextEntitiesToFront() {
    for (auto element: TextEntityMap){
        TextEntity* textEntity = (element.second);
        removeEntity(textEntity);
        addEntity(textEntity);
    }
}

int Scene::getWindowWidth() { return game->getWindowWidth();}
int Scene::getWindowHeight() { return game->getWindowHeight();}

Scene::~Scene() {
    for (auto i : EntityList){
        delete i;
    }
}
