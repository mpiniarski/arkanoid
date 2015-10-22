#include "MenuScene.h"
#include "Engine/TextEntity.h"
#include "Platform.h"
#include "Ball.h"

MenuScene::MenuScene(const std::string &name, Game *game) : Scene(name, game) {
    initialize();
}

void MenuScene::uploadTextures() {
//    resourceManager.loadTextureFromFile("texture1","res/img/background3.jpg");
}

void MenuScene::uploadFonts() {
//    resourceManager.loadFontFromFile("font1","res/font/8_bit_operator/8bitOperatorPlus8-Bold.ttf");
    resourceManager.loadFontFromFile("font1","res/font/pixcel/Pixcel.ttf");
//    resourceManager.loadFontFromFile("font1","res/font/highscore_hero/HighscoreHero.ttf");
}

void MenuScene::createEntities() {
    TextEntity *entity = new TextEntity(this,"Arkanoid",resourceManager.getFontFromMap("font1"));
    text = entity;
    entity->setCharacterSize(111);
    entity->setPosition((800 - entity->getWidth()) / 2, (600 - entity->getHeight())/2);
    addEntity(entity);
}

void MenuScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) ) {
        if( event.type == sf::Event::Closed ) {
            game->Window.close();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
            game->Window.close();
        }
        else break;
    }
}

