#include "GameplayScene.h"
#include "MenuScene.h"
#include <SFML/Graphics.hpp>

#include "Platform.h"
#include "Ball.h"
#include "Brick.h"


GameplayScene::GameplayScene(Game *game): Scene(game) {
    initialize();
}

void GameplayScene::uploadResources() {
    resourceManager.loadTextureFromFile("Platform","res/img/hostile_shot.png");
    resourceManager.loadTextureFromFile("Ball","res/img/ball.png");
    resourceManager.loadTextureFromFile("Brick1","res/img/brick.png");
}

void GameplayScene::createEntities() {

    platform = new Platform(this,resourceManager.getTextureFromMap("Platform"));
    addEntity(platform);

    ball = new Ball(this,resourceManager.getTextureFromMap("Ball"),platform);
    addEntity(ball);

    Brick *brick;
    for (int i=1; i<=10; i++){
        for (int j=1; j<=5; j++){
            brick = new Brick(this, resourceManager.getTextureFromMap("Brick1"));
            brick->setPosition(brick->getWidth()*i,100+brick->getHeight()*j);
            addEntity(brick);
            ball->addCollisionMaker(brick);
        }
    }


}

void GameplayScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) )
    {
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
            exitScene(new MenuScene(game));
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

void GameplayScene::exitScene(Scene* nextScene){
    if(nextScene != NULL){
        Scene::exitScene(nextScene);
    }
    else{
        Scene::exitScene(new MenuScene(game));
    }
}
