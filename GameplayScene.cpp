#include "GameplayScene.h"


GameplayScene::GameplayScene(Game *game): Scene(game) {
    initialize();
}

void GameplayScene::uploadTextures() {
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
        else break;
    }
}
