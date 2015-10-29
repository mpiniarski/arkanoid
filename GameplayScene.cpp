#include "GameplayScene.h"
#include "MenuScene.h"
#include <SFML/Graphics.hpp>


GameplayScene::GameplayScene(Game *game): Scene(game) {
    initialize();
}

void GameplayScene::uploadResources() {
    resourceManager.loadTextureFromFile("texture1","res/img/hostile_shot.png");
    resourceManager.loadTextureFromFile("texture2","res/img/ball.png");
}

void GameplayScene::createEntities() {

    Platform *entity = new Platform(this,resourceManager.getTextureFromMap("texture1"));
    platform = entity;
    addEntity(entity);

    Ball *entity2 = new Ball(this,resourceManager.getTextureFromMap("texture2"));
    ball = entity2;
    ball->addCollisionMaker(platform);
    addEntity(entity2);
}

void GameplayScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) )
    {
        if( event.type == sf::Event::Closed ) {
            game->Window.close();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
            MenuScene *menu_scene = new MenuScene(game);
            game->launchScene(menu_scene);
        }
        else if( event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                platform->changeDirection(DIRECTION::LEFT);
                isKeyHeld[DIRECTION::LEFT] = true;
            }
            else if (event.key.code == sf::Keyboard::Right) {
                platform->changeDirection(DIRECTION::RIGHT);
                isKeyHeld[DIRECTION::RIGHT] = true;
            }
        }
        else if( event.type == sf::Event::KeyReleased ) {
            if( event.key.code == sf::Keyboard::Left ) {
                platform->resetDirection(DIRECTION::LEFT);
                isKeyHeld[DIRECTION::LEFT] = false;
                if (isKeyHeld[DIRECTION::RIGHT]) platform->changeDirection(DIRECTION::RIGHT);
            }
            else if( event.key.code == sf::Keyboard::Right ) {
                platform->resetDirection(DIRECTION::RIGHT);
                isKeyHeld[DIRECTION::RIGHT] = false;
                if (isKeyHeld[DIRECTION::LEFT]) platform->changeDirection(DIRECTION::LEFT);
            }
        }
        else break;
    }
}
