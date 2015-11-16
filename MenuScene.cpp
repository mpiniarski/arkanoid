#include "MenuScene.h"
#include "GameplayScene.h"
#include "EditMapScene.h"
#include <map>

MenuScene::MenuScene(Game *game) : Scene(game) {
    initialize();
    chosenOption = OPTION::NEWGAME;
    markOption();
}

void MenuScene::uploadResources() {
    resourceManager.loadTextureFromFile("texture1","res/img/menu_background.png");
    resourceManager.loadFontFromFile("font1","res/font/8_bit_operator/8bitOperatorPlus8-Bold.ttf");
//    resourceManager.loadFontFromFile("font1","res/font/pixcel/Pixcel.ttf");
//    resourceManager.loadFontFromFile("font1","res/font/highscore_hero/HighscoreHero.ttf");
}

void MenuScene::createEntities() {
    GraphicalEntity *bg = new GraphicalEntity(this, "Background", resourceManager.getTextureFromMap("texture1"));
    bg->stretchToWindowSize();
    addEntity(bg);

    TextEntity *title = new TextEntity(this, "Arkanoid", resourceManager.getFontFromMap("font1"));
    title->setCharacterSize(111);
    title->setPosition( (game->getWindowWidth() - title->getWidth())/2, (game->getWindowHeight() - title->getHeight())/9);
    addEntity(title);
    TextEntityMap.insert( {"title",title} );

    TextEntity *new_game = new TextEntity(this, "NEW GAME", resourceManager.getFontFromMap("font1"));
    new_game->setCharacterSize(40);
    new_game->setPosition( (game->getWindowWidth() - new_game->getWidth())/2, 2*(game->getWindowHeight() - new_game->getHeight())/5);
    addEntity(new_game);
    TextEntityMap.insert( {"new_game",new_game} );

    TextEntity *edit_map = new TextEntity(this, "EDIT YOUR MAP", resourceManager.getFontFromMap("font1"));
    edit_map->setCharacterSize(40);
    edit_map->setPosition( (game->getWindowWidth() - edit_map->getWidth())/2, 3*(game->getWindowHeight() - edit_map->getHeight())/5);
    addEntity(edit_map);
    TextEntityMap.insert( {"edit_map",edit_map} );

    TextEntity *exit = new TextEntity(this, "EXIT", resourceManager.getFontFromMap("font1"));
    exit->setCharacterSize(40);
    exit->setPosition( (game->getWindowWidth() - exit->getWidth())/2, 4*(game->getWindowHeight() - exit->getHeight())/5);
    addEntity(exit);
    TextEntityMap.insert( {"exit",exit} );
}

void MenuScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) ) {
        if( event.type == sf::Event::Closed ) {
            exitScene();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
            exitScene();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && chosenOption == OPTION::NEWGAME ) {
            exitScene(new GameplayScene(game,1));
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && chosenOption == OPTION::EDITMAP ) {
            exitScene(new EditMapScene(game));
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && chosenOption == OPTION::EXIT ) {
            exitScene();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down ) {
            changeOption(DIRECTION::DOWN);
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up ) {
            changeOption(DIRECTION::UP);
        }
        else break;
    }
}

void MenuScene::changeOption(int direction) {
    if(direction == DIRECTION::DOWN && chosenOption <= OPTION::EXIT) chosenOption++;
    else if(direction == DIRECTION::UP && chosenOption >= OPTION::NEWGAME) chosenOption--;
    markOption();
}

void MenuScene::markOption() {
    auto new_game = TextEntityMap.find("new_game");
    auto edit_map = TextEntityMap.find("edit_map");
    auto exit = TextEntityMap.find("exit");
    sf::Color red = sf::Color(255,0,0);
    sf::Color black = sf::Color(255,255,255);

    if(chosenOption == OPTION::NEWGAME) {
        new_game->second->setColor(red);
        edit_map->second->setColor(black);
        exit->second->setColor(black);
    }
    else if(chosenOption == OPTION::EDITMAP) {
        new_game->second->setColor(black);
        edit_map->second->setColor(red);
        exit->second->setColor(black);
    }
    else if(chosenOption == OPTION::EXIT) {
        new_game->second->setColor(black);
        edit_map->second->setColor(black);
        exit->second->setColor(red);
    }
}
