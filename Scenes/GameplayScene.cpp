#include "GameplayScene.h"

#include "MenuScene.h"
#include "../Entities/Platform.h"
#include "../Entities/Ball.h"
#include "../Entities/Brick.h"
#include "../Entities/SolidBrick.h"
#include "../Entities/Barrier.h"
#include "ResultScene.h"

#include <fstream>


GameplayScene::GameplayScene(Game *game, int levelNumber, int points) : Scene(game) {
    if(levelNumber == 1) { this->points = 0; }
    this->points += points;
    this->levelNumber = levelNumber;
    initialize();
    this->entitiesLeft = 0;
    for(int i = 0; i < 4; i++) { isKeyHeld[i] = 0; }
    switch(levelNumber){
        case 1:
            loadMapFromFile("map1.ark");
            break;
        case 2:
            loadMapFromFile("map2.ark");
            break;
        case 3:
            loadMapFromFile("map3.ark");
            break;
    }
    moveTextEntitiesToFront();
}

GameplayScene::GameplayScene(Game *game, std::list<GraphicalEntity *> entityList) : Scene(game) {
    points = 0;
    levelNumber = -1;
    initialize();
    for(int i = 0; i < 4; i++) { isKeyHeld[i] = 0; }
    this->entitiesLeft = 0;
    for (auto i: entityList){
        i->setTexture(resourceManager.getTextureFromMap(i->type));
        addEntity(i);
        ball->addCollisionMaker(i);
        this->entitiesLeft++;
    }
    moveTextEntitiesToFront();
}

void GameplayScene::uploadResources() {
    resourceManager.loadTextureFromFile("Platform","res/img/platform.png");
    resourceManager.loadTextureFromFile("Ball","res/img/ball.png");
    resourceManager.loadTextureFromFile("Brick","res/img/brick.png");
    resourceManager.loadTextureFromFile("SolidBrick","res/img/solidBrick.png");
    resourceManager.loadTextureFromFile("Barrier","res/img/barrier.png");
    resourceManager.loadFontFromFile("font1","res/font/new-academy/new-academy.ttf");
}

void GameplayScene::createEntities() {
    platform = new Platform(this,resourceManager.getTextureFromMap("Platform"));
    addEntity(platform);

    ball = new Ball(this,resourceManager.getTextureFromMap("Ball"),platform);
    addEntity(ball);

    TextEntity* pointsText = new TextEntity(this, "Points: ", resourceManager.getFontFromMap("font1"));
    pointsText->setString("Points: " + std::to_string(points) );
    pointsText->setCharacterSize(40);
    pointsText->setPosition(10, -12);
    addEntity(pointsText);
    TextEntityMap.insert({ "pointsText", pointsText });

    if (levelNumber > 0){
        TextEntity* levelNumberText = new TextEntity(this, "LEVEL " + std::to_string(levelNumber), resourceManager.getFontFromMap("font1"));
        levelNumberText->setCharacterSize(40);
        levelNumberText->setPosition(getWindowWidth()-230, -12);
        addEntity(levelNumberText);
        TextEntityMap.insert({ "levelNumberText", levelNumberText });
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
        Scene::exitScene(new ResultScene(game, points, this->entitiesLeft));
    }
}

void GameplayScene::loadMapFromFile(std::string filePath) {
    std::string type;
    int pos_x,pos_y;
    std::ifstream file;
    file.open(filePath.c_str());
    if( !file.good() ) return;
    while(1){
        file>>type;
        file>>pos_x;
        file>>pos_y;
        if (file.eof()) break;

        if(type=="Brick"){
            Brick *brick = new Brick(this,resourceManager.getTextureFromMap("Brick"));
            brick->setPosition(pos_x,pos_y);
            addEntity(brick);
            ball->addCollisionMaker(brick);
            this->entitiesLeft++;
        }
        if(type=="SolidBrick"){
            SolidBrick *solidBrick = new SolidBrick(this,resourceManager.getTextureFromMap("SolidBrick"));
            solidBrick->setPosition(pos_x,pos_y);
            addEntity(solidBrick);
            ball->addCollisionMaker(solidBrick);
            this->entitiesLeft++;
        }
        if(type=="Barrier"){
            Barrier *barrier = new Barrier(this,resourceManager.getTextureFromMap("Barrier"));
            barrier->setPosition(pos_x,pos_y);
            addEntity(barrier);
            ball->addCollisionMaker(barrier);
        }
    }
    file.close();
}

void GameplayScene::addPoints(int points) {
    this->points += points;
    TextEntity* pointsText = TextEntityMap.find("pointsText")->second;
    pointsText->setString("Points: " + std::to_string(this->points) );
}

void GameplayScene::finishGame() {
    if(this->entitiesLeft == 0 && levelNumber < 3 && levelNumber > 0) {
        levelNumber++;
        Scene::exitScene(new GameplayScene(game, levelNumber, this->points));
    }
    else Scene::exitScene(new ResultScene(game, points, this->entitiesLeft));
}
