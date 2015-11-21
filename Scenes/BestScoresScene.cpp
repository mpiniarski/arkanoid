#include "BestScoresScene.h"

#include "../Engine/GraphicalEntity.h"
#include "../Engine/TextEntity.h"
#include "MenuScene.h"

#include <fstream>

BestScoresScene::BestScoresScene(Game *game) : Scene(game) {
    initialize();
}

void BestScoresScene::uploadResources() {
    resourceManager.loadTextureFromFile("Background","res/img/menu_background.jpg");
    resourceManager.loadFontFromFile("font1","res/font/new-academy/new-academy.ttf");
}

void BestScoresScene::createEntities() {
    GraphicalEntity *bg = new GraphicalEntity(this, "Background", resourceManager.getTextureFromMap("Background"));
    bg->stretchToWindowSize();
    addEntity(bg);

    TextEntity *header = new TextEntity(this, "Top scores", resourceManager.getFontFromMap("font1"));
    header->setCharacterSize(90);
    header->setPosition( (game->getWindowWidth() - header->getWidth())/2, (game->getWindowHeight() - header->getHeight())/15);
    addEntity(header);
    TextEntityMap.insert( {"header",header} );

    TextEntity *legend = new TextEntity(this, "Click Enter\nto return to menu", resourceManager.getFontFromMap("font1"));
    legend->setCharacterSize(30);
    legend->setPosition( 10, 14*(game->getWindowHeight() - legend->getHeight())/15);
    addEntity(legend);
    TextEntityMap.insert( {"legend",legend} );

    std::string text = textFileToScoreList("score.txt");
    TextEntity *scores = new TextEntity(this, text, resourceManager.getFontFromMap("font1"));
    scores->setCharacterSize(50);
    scores->setPosition( (game->getWindowWidth() - scores->getWidth())/2, 3*(game->getWindowHeight())/15);
    addEntity(scores);
    TextEntityMap.insert( {"scores",scores} );
}

std::string BestScoresScene::textFileToScoreList(std::string filePath) {
    std::list<std::string> scoreList;
    std::ifstream file;
    file.open(filePath.c_str());
    if( !file.good() ) return "";
    std::string score;
    while(true) {
        file >> score;
        if(file.eof()) break;
        scoreList.push_back(score);
    }

    std::string text = "";
    int counter = 1;
    while( counter <= 10 && !scoreList.empty() ) {
        score = scoreList.front();
        text += std::to_string(counter) + ".\t" + score + "\n";
        counter++;
        scoreList.pop_front();
    }
    file.close();

    return text;
}

void BestScoresScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) ) {
        if( event.type == sf::Event::Closed ) {
            exitScene();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return ) {
            exitScene(new MenuScene(game));
        }
        else break;
    }
}

