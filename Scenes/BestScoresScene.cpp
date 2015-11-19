#include "BestScoresScene.h"

#include "../Engine/GraphicalEntity.h"
#include "../Engine/TextEntity.h"
#include "MenuScene.h"

BestScoresScene::BestScoresScene(Game *game) : Scene(game) {
    initialize();
}

void BestScoresScene::uploadResources() {
    resourceManager.loadTextureFromFile("texture1","res/img/menu_background.png");
    resourceManager.loadFontFromFile("font1","res/font/new-academy/new-academy.ttf");
}

void BestScoresScene::createEntities() {
    GraphicalEntity *bg = new GraphicalEntity(this, "Background", resourceManager.getTextureFromMap("texture1"));
    bg->stretchToWindowSize();
    addEntity(bg);

    TextEntity *title = new TextEntity(this, "Arkanoid", resourceManager.getFontFromMap("font1"));
    title->setCharacterSize(111);
    title->setPosition( (game->getWindowWidth() - title->getWidth())/2, (game->getWindowHeight() - title->getHeight())/9);
    addEntity(title);
    TextEntityMap.insert( {"title",title} );
}

void BestScoresScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) ) {
        if( event.type == sf::Event::Closed ) {
            exitScene();
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
            exitScene(new MenuScene(game));
        }
        else break;
    }
}
