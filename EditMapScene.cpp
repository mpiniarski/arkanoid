#include "EditMapScene.h"
#include "Brick.h"
#include "MenuScene.h"
#include "GameplayScene.h"

EditMapScene::EditMapScene(Game *game) : Scene(game) {
    initialize();
}

void EditMapScene::uploadResources() {
    resourceManager.loadTextureFromFile("Platform","res/img/hostile_shot.png");
    resourceManager.loadTextureFromFile("Brick1","res/img/brick.png");
}

void EditMapScene::createEntities() {
    Platform* platform =new Platform(this,resourceManager.getTextureFromMap("Platform"));
    addEntity(platform);

//    Brick *brick;
    for (int i=1; i<=1; i++){
        for (int j=1; j<=1; j++){
            brickCursor = new Brick(this, resourceManager.getTextureFromMap("Brick1"));
            sf::Color color = brickCursor->getColor();
            brickCursor->setColor(sf::Color(color.r,color.g, color.b,111));
            brickCursor->setPosition(brickCursor->getWidth()*i,100+brickCursor->getHeight()*j);
            addEntity(brickCursor);
        }
    }
}

void EditMapScene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) ) {
        if( event.type == sf::Event::KeyPressed ) {
            if ( event.key.code == sf::Keyboard::Escape ) {
                exitScene(new MenuScene(game));
            }
            else if( event.key.code == sf::Keyboard::Right ) {
                moveEntity(brickCursor, DIRECTION::RIGHT);
            }
            else if( event.key.code == sf::Keyboard::Left ) {
                moveEntity(brickCursor, DIRECTION::LEFT);
            }
            else if( event.key.code == sf::Keyboard::Up ) {
                moveEntity(brickCursor, DIRECTION::UP);
            }
            else if( event.key.code == sf::Keyboard::Down ) {
                moveEntity(brickCursor, DIRECTION::DOWN);
            }
            else if( event.key.code == sf::Keyboard::Return ) {
                Brick* brick;
                brick = new Brick(this, resourceManager.getTextureFromMap("Brick1"));
                sf::Color color = brick->getColor();
                brick->setColor(sf::Color(color.r,color.g, color.b,255));
                brick->setPosition(brickCursor->getPosition().x,brickCursor->getPosition().y);
                addEntity(brick);
                mapEntities.push_back(brick);
            }
            else if( event.key.code == sf::Keyboard::P ) {
                loadMap();
            }
        }
    }
}

void EditMapScene::moveEntity(Brick *brickCursor, int direction) {
    float x = brickCursor->getPosition().x;
    float y = brickCursor->getPosition().y;
    float width = brickCursor->getWidth();
    float height = brickCursor->getHeight();

    if( direction == DIRECTION::RIGHT ) {
        float pos_x = x + width;
        float pos_y = y;
        if(pos_x >= game->getWindowWidth()) pos_x = game->getWindowWidth() - width;
        brickCursor->setPosition(pos_x, pos_y);
    }
    else if( direction == DIRECTION::LEFT ) {
        float pos_x = x - width;
        float pos_y = y;
        if(pos_x <= 0) pos_x = 0;
        brickCursor->setPosition(pos_x, pos_y);
    }
    else if( direction == DIRECTION::UP ) {
        float pos_x = x;
        float pos_y = y - height;
        if(pos_y <= 0) pos_y = 0;
        brickCursor->setPosition(pos_x, pos_y);
    }
    else if( direction == DIRECTION::DOWN ) {
        float pos_x = x;
        float pos_y = y + height;
        float minHeight = height*16;
        if(pos_y >= minHeight) pos_y = minHeight - height;
        brickCursor->setPosition(pos_x, pos_y);
    }
}

void EditMapScene::exitScene(Scene *nextScene) {
    if(nextScene != NULL){
        Scene::exitScene(nextScene);
    }
    else{
        Scene::exitScene(new MenuScene(game));
    }
}

void EditMapScene::loadMap() {
    GameplayScene* gameplayScene = new GameplayScene(game, mapEntities);
    for(auto i : mapEntities){
        removeEntity(i);
        i->scene = gameplayScene;
    }
    exitScene(gameplayScene);
}
