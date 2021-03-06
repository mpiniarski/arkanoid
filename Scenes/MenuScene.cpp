#include "MenuScene.h"

#include "GameplayScene.h"
#include "EditMapScene.h"
#include "BestScoresScene.h"

MenuScene::MenuScene(Game *game) : Scene(game) {
    initialize();
    chosenOption = OPTION::NEWGAME;
    markOption();
}

void MenuScene::uploadResources() {
    resourceManager.loadTextureFromFile("Background","res/img/menu_background.jpg");
    resourceManager.loadFontFromFile("Font1","res/font/new-academy/new-academy.ttf");
}

void MenuScene::createEntities() {
    GraphicalEntity *bg = new GraphicalEntity(this, "Background", resourceManager.getTextureFromMap("Background"));
    bg->stretchToWindowSize();
    addEntity(bg);

    TextEntity *title = new TextEntity(this, "Arkanoid", resourceManager.getFontFromMap("Font1"));
    title->setCharacterSize(111);
    title->setPosition( (game->getWindowWidth() - title->getWidth())/2 , 30);
//    title->setColor(sf::Color(111,0,0));
    addEntity(title);
    textEntityMap.insert({"title", title} );

    TextEntity *new_game = new TextEntity(this, "NEW GAME", resourceManager.getFontFromMap("Font1"));
    new_game->setCharacterSize(40);
    new_game->setPosition( (game->getWindowWidth() - new_game->getWidth())/2, 2*(game->getWindowHeight() - new_game->getHeight())/6);
    addEntity(new_game);
    textEntityMap.insert({"new_game", new_game} );

    TextEntity *edit_map = new TextEntity(this, "EDIT YOUR MAP", resourceManager.getFontFromMap("Font1"));
    edit_map->setCharacterSize(40);
    edit_map->setPosition( (game->getWindowWidth() - edit_map->getWidth())/2, 3*(game->getWindowHeight() - edit_map->getHeight())/6);
    addEntity(edit_map);
    textEntityMap.insert({"edit_map", edit_map} );

    TextEntity *best_scores = new TextEntity(this, "BEST SCORES", resourceManager.getFontFromMap("Font1"));
    best_scores->setCharacterSize(40);
    best_scores->setPosition( (game->getWindowWidth() - best_scores->getWidth())/2, 4*(game->getWindowHeight() - best_scores->getHeight())/6);
    addEntity(best_scores);
    textEntityMap.insert({"best_scores", best_scores} );

    TextEntity *exit = new TextEntity(this, "EXIT", resourceManager.getFontFromMap("Font1"));
    exit->setCharacterSize(40);
    exit->setPosition( (game->getWindowWidth() - exit->getWidth())/2, 5*(game->getWindowHeight() - exit->getHeight())/6);
    addEntity(exit);
    textEntityMap.insert({"exit", exit} );
}

void MenuScene::handleEvents() {
    sf::Event event;
    while( game->window.pollEvent(event ) ) {
        if( event.type == sf::Event::Closed ) {
            exitScene();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
            exitScene();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && chosenOption == OPTION::NEWGAME ) {
            exitScene(new GameplayScene(game,1,0));
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && chosenOption == OPTION::EDITMAP ) {
            exitScene(new EditMapScene(game));
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && chosenOption == OPTION::BESTSCORES ) {
            exitScene(new BestScoresScene(game));
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
    auto new_game = textEntityMap.find("new_game");
    auto edit_map = textEntityMap.find("edit_map");
    auto best_scores = textEntityMap.find("best_scores");
    auto exit = textEntityMap.find("exit");
    sf::Color red = sf::Color(150,0,0);
    sf::Color def = sf::Color(255,255,255);

    if(chosenOption == OPTION::NEWGAME) {
        new_game->second->setColor(red);
        edit_map->second->setColor(def);
        best_scores->second->setColor(def);
        exit->second->setColor(def);
    }
    else if(chosenOption == OPTION::EDITMAP) {
        new_game->second->setColor(def);
        edit_map->second->setColor(red);
        best_scores->second->setColor(def);
        exit->second->setColor(def);
    }
    else if(chosenOption == OPTION::BESTSCORES) {
        new_game->second->setColor(def);
        edit_map->second->setColor(def);
        best_scores->second->setColor(red);
        exit->second->setColor(def);
    }
    else if(chosenOption == OPTION::EXIT) {
        new_game->second->setColor(def);
        edit_map->second->setColor(def);
        best_scores->second->setColor(def);
        exit->second->setColor(red);
    }
}
