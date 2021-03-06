#include "GameplayScene.h"

#include "MenuScene.h"
#include "../Entities/Platform.h"
#include "../Entities/Ball.h"
#include "../Entities/Brick.h"
#include "../Entities/SolidBrick.h"
#include "../Entities/Barrier.h"
#include "../Entities/ColorBonus.h"
#include "ResultScene.h"
#include "../Entities/PlatformResizeBonus.h"

#include <fstream>

GameplayScene::GameplayScene(Game *game, int levelNumber, int points) : Scene(game) {
    this->points = points;
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
    levelNumber = 0;
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
    switch (levelNumber) {
        case 0:
            resourceManager.loadTextureFromFile("Background","res/img/bg1.jpg");
            break;
        case 1:
            resourceManager.loadTextureFromFile("Background","res/img/bg1.jpg");
            break;
        case 2:
            resourceManager.loadTextureFromFile("Background","res/img/bg2.jpg");
            break;
        case 3:
            resourceManager.loadTextureFromFile("Background","res/img/bg3.jpg");
            break;
    }
    resourceManager.loadTextureFromFile("Platform","res/img/platform.png");
    resourceManager.loadTextureFromFile("Ball","res/img/ball.png");
    resourceManager.loadTextureFromFile("Brick","res/img/brick.png");
    resourceManager.loadTextureFromFile("SolidBrick","res/img/solidBrick.png");
    resourceManager.loadTextureFromFile("Barrier","res/img/barrier.png");
    resourceManager.loadFontFromFile("font1","res/font/new-academy/new-academy.ttf");
}

void GameplayScene::createEntities() {
    GraphicalEntity *bg = new GraphicalEntity(this, "Background", resourceManager.getTextureFromMap("Background"));
    bg->stretchToWindowSize();
    addEntity(bg);

    platform = new Platform(this,resourceManager.getTextureFromMap("Platform"));
    addEntity(platform);

    ball = new Ball(this,resourceManager.getTextureFromMap("Ball"),platform);
    addEntity(ball);

    TextEntity* pointsText = new TextEntity(this, "Points: ", resourceManager.getFontFromMap("font1"));
    pointsText->setString("Points: " + std::to_string(points) );
    pointsText->setCharacterSize(40);
    pointsText->setPosition(10, -12);
    addEntity(pointsText);
    textEntityMap.insert({"pointsText", pointsText });

    if (levelNumber > 0){
        TextEntity* levelNumberText = new TextEntity(this, "LEVEL " + std::to_string(levelNumber), resourceManager.getFontFromMap("font1"));
        levelNumberText->setCharacterSize(40);
        levelNumberText->setPosition(getWindowWidth()-230, -12);
        addEntity(levelNumberText);
        textEntityMap.insert({"levelNumberText", levelNumberText });
    }
}

void GameplayScene::handleEvents() {
    sf::Event event;
    while( game->window.pollEvent(event ) )
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
        saveScore("score.txt");
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

void GameplayScene::saveScore(std::string filePath) {
    std::list<int> scoreList;
    std::ifstream file;
    file.open(filePath.c_str());
    if( !file.good() ) return;
    int score;
    while(true) {
        file >> score;
        if(file.eof()) break;
        scoreList.push_back(score);
    }
    scoreList.push_back(points);

    scoreList.sort();

    file.close();

    std::ofstream ofile;
    ofile.open(filePath.c_str());
    if( !ofile.good() ) return;

    int counter = 10;
    int last_value = -1;
    while(!scoreList.empty() && counter > 0) {
        score = scoreList.back();
        if(score != last_value && score != 0) {
            ofile << score << "\n";
            counter--;
            last_value = score;
        }
        scoreList.pop_back();
    }
    ofile.close();
}

void GameplayScene::addPoints(int points) {
    this->points += points;
    TextEntity* pointsText = textEntityMap.find("pointsText")->second;
    pointsText->setString("Points: " + std::to_string(this->points) );
}

void GameplayScene::subtractEntity() {
    entitiesLeft--;
    if(!entitiesLeft) winGame();
}

void GameplayScene::winGame() {
    if(this->entitiesLeft == 0 && levelNumber < 3 && levelNumber > 0) {
        levelNumber++;
        Scene::exitScene(new GameplayScene(game, levelNumber, this->points));
    }
    else {
        saveScore("score.txt");
        Scene::exitScene(new ResultScene(game, points, this->entitiesLeft));
    }
}

void GameplayScene::generateColorBonus() {
    ColorBonus* bonus = new ColorBonus(this,resourceManager.getTextureFromMap("Ball"),platform);
    addEntity(bonus);
}

void GameplayScene::generatePlatformResizeBonus() {
    PlatformResizeBonus* bonus = new PlatformResizeBonus(this,resourceManager.getTextureFromMap("Ball"),platform);
    addEntity(bonus);
}
