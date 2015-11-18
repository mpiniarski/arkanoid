#include "ResultScene.h"

#include "../Engine/TextEntity.h"
#include "../Engine/GraphicalEntity.h"
#include "MenuScene.h"

#include <cstring>

ResultScene::ResultScene(Game *game, int points, int entitiesLeft) : Scene(game) {
    if(entitiesLeft) result = RESULT::LOSE;
    else result = RESULT::WIN;
    this->points = points;
    initialize();
}

void ResultScene::uploadResources() {
    resourceManager.loadTextureFromFile("texture1","res/img/menu_background.png");
    resourceManager.loadFontFromFile("font1","res/font/new-academy/new-academy.ttf");
}

void ResultScene::createEntities() {
    GraphicalEntity *bg = new GraphicalEntity(this, "Background", resourceManager.getTextureFromMap("texture1"));
    bg->stretchToWindowSize();
    addEntity(bg);

    if(result == RESULT::WIN) {
        TextEntity* congrats = new TextEntity(this, "CONGRATULATIONS", resourceManager.getFontFromMap("font1"));
        congrats->setCharacterSize(75);
        congrats->setPosition((game->getWindowWidth() - congrats->getWidth())/2, game->getWindowHeight()/8);
        addEntity(congrats);
        TextEntityMap.insert({ "congrats", congrats });

        TextEntity* win = new TextEntity(this, "YOU WON!", resourceManager.getFontFromMap("font1"));
        win->setCharacterSize(75);
        win->setPosition((game->getWindowWidth() - win->getWidth())/2, 2*(game->getWindowHeight()/8));
        addEntity(win);
        TextEntityMap.insert({ "win", win });
    }
    else if(result == RESULT::LOSE) {
        TextEntity* sorry = new TextEntity(this, "I'M SORRY", resourceManager.getFontFromMap("font1"));
        sorry->setCharacterSize(75);
        sorry->setPosition((game->getWindowWidth() - sorry->getWidth())/2, (game->getWindowHeight()/8));
        addEntity(sorry);
        TextEntityMap.insert({ "sorry", sorry });

        TextEntity* lose = new TextEntity(this, "YOU LOST!", resourceManager.getFontFromMap("font1"));
        lose->setCharacterSize(75);
        lose->setPosition((game->getWindowWidth() - lose->getWidth())/2, 2*(game->getWindowHeight()/8));
        addEntity(lose);
        TextEntityMap.insert({ "lose", lose });
    }
    TextEntity* score = new TextEntity(this, "YOUR SCORE:", resourceManager.getFontFromMap("font1"));
    score->setString("Points: " + std::to_string(points) );
    score->setCharacterSize(50);
    score->setPosition((game->getWindowWidth() - score->getWidth())/2, 4*(game->getWindowHeight()/8));
    addEntity(score);
    TextEntityMap.insert({ "score", score });

    TextEntity* enter = new TextEntity(this, "CLICK ENTER TO RETURN TO MENU", resourceManager.getFontFromMap("font1"));
    enter->setCharacterSize(35);
    enter->setPosition((game->getWindowWidth() - enter->getWidth())/2, 5*(game->getWindowHeight()/8));
    addEntity(enter);
    TextEntityMap.insert({ "enter", enter });
}

void ResultScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) ) {
        if( event.type == sf::Event::Closed ) {
            exitScene(new MenuScene(game));
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return ) {
            exitScene(new MenuScene(game));
        }
        else break;
    }
}
