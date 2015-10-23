#include "MenuScene.h"
#include "Engine/TextEntity.h"
#include "Platform.h"
#include "Ball.h"

MenuScene::MenuScene(const std::string &name, Game *game) : Scene(name, game) {
    initialize();
    chosenOption = OPTION::NEWGAME;
    markOption();
}

void MenuScene::uploadTextures() {
//    resourceManager.loadTextureFromFile("texture1","res/img/background3.jpg");
}

void MenuScene::uploadFonts() {
    resourceManager.loadFontFromFile("font1","res/font/8_bit_operator/8bitOperatorPlus8-Bold.ttf");
//    resourceManager.loadFontFromFile("font1","res/font/pixcel/Pixcel.ttf");
//    resourceManager.loadFontFromFile("font1","res/font/highscore_hero/HighscoreHero.ttf");
}

void MenuScene::createEntities() {
    title = new TextEntity(this,"Arkanoid",resourceManager.getFontFromMap("font1"));
    title->setCharacterSize(111);
    title->setPosition((800 - title->getWidth()) / 2, (600 - title->getHeight())/9);
    addEntity(title);

    new_game = new TextEntity(this,"NEW GAME",resourceManager.getFontFromMap("font1"));
    new_game->setCharacterSize(40);
    new_game->setPosition((800 - new_game->getWidth()) / 2, 2*(600 - new_game->getHeight())/5);
    addEntity(new_game);

    edit_map = new TextEntity(this,"EDIT YOUR MAP",resourceManager.getFontFromMap("font1"));
    edit_map->setCharacterSize(40);
    edit_map->setPosition((800 - edit_map->getWidth()) / 2, 3*(600 - edit_map->getHeight())/5);
    addEntity(edit_map);

    exit = new TextEntity(this,"EXIT",resourceManager.getFontFromMap("font1"));
    exit->setCharacterSize(40);
    exit->setPosition((800 - exit->getWidth()) / 2, 4*(600 - exit->getHeight())/5);
    addEntity(exit);
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
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && chosenOption == OPTION::EXIT ) {
            game->Window.close();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down ) {
            changeOption(DIRECTION::DOWN);
            markOption();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up ) {
            changeOption(DIRECTION::UP);
            markOption();
        }
        else break;
    }
}

void MenuScene::changeOption(int direction) {
    if(direction == DIRECTION::DOWN && chosenOption <= OPTION::EXIT) chosenOption++;
    else if(direction == DIRECTION::UP && chosenOption >= OPTION::NEWGAME) chosenOption--;
}

void MenuScene::markOption() {
    if(chosenOption == OPTION::NEWGAME) {
        new_game->setColor(sf::Color(255,0,0));
        edit_map->setColor(sf::Color(255,255,255));
        exit->setColor(sf::Color(255,255,255));
    }
    else if(chosenOption == OPTION::EDITMAP) {
        new_game->setColor(sf::Color(255,255,255));
        edit_map->setColor(sf::Color(255,0,0));
        exit->setColor(sf::Color(255,255,255));
    }
    else if(chosenOption == OPTION::EXIT) {
        new_game->setColor(sf::Color(255,255,255));
        edit_map->setColor(sf::Color(255,255,255));
        exit->setColor(sf::Color(255,0,0));
    }
}
