#include "EditMapScene.h"

#include "MenuScene.h"
#include "GameplayScene.h"
#include "../Entities/SolidBrick.h"
#include "../Entities/Barrier.h"
#include "../Entities/Platform.h"
#include "../Entities/Ball.h"
#include "../Entities/Brick.h"

#include <fstream>

EditMapScene::EditMapScene(Game *game) : Scene(game) {
    initialize();
    chosenCursor = TYPE::BRICK;
}

void EditMapScene::uploadResources() {
    resourceManager.loadTextureFromFile("Background","res/img/bg1.jpg");
    resourceManager.loadTextureFromFile("Platform","res/img/platform.png");
    resourceManager.loadTextureFromFile("Brick","res/img/brick.png");
    resourceManager.loadTextureFromFile("SolidBrick","res/img/solidBrick.png");
    resourceManager.loadTextureFromFile("Barrier","res/img/barrier.png");
    resourceManager.loadFontFromFile("Font1","res/font/new-academy/new-academy.ttf");
}

void EditMapScene::createEntities() {
    GraphicalEntity *bg = new GraphicalEntity(this, "Background", resourceManager.getTextureFromMap("Background"));
    bg->stretchToWindowSize();
    addEntity(bg);

    Platform* platform =new Platform(this,resourceManager.getTextureFromMap("Platform"));
    addEntity(platform);

    makeCursor(0,0);

    std::string text = "Place element: Space\nUndo: Backspace\nChange type: C\nPlay map: Enter\nSave map: S\nLoad last map: L\nExit edit mode: Escape";

    TextEntity* legend = new TextEntity(this, text, resourceManager.getFontFromMap("Font1"));
    legend->setCharacterSize(30);
    legend->setPosition(10, game->getWindowHeight() - 1.1*legend->getHeight());
    addEntity(legend);
    textEntityMap.insert({"legend", legend });
}

void EditMapScene::makeCursor(float pos_x, float pos_y) {
    switch(chosenCursor) {
        case TYPE::BRICK:
            brickCursor = new Brick(this, resourceManager.getTextureFromMap("Brick"));
            break;
        case TYPE::SOLIDBRICK:
            brickCursor = new SolidBrick(this, resourceManager.getTextureFromMap("SolidBrick"));
            break;
        case TYPE::BARRIER:
            brickCursor = new Barrier(this, resourceManager.getTextureFromMap("Barrier"));
            break;
        default:
            brickCursor = new Brick(this, resourceManager.getTextureFromMap("Brick"));
            break;

    }
    brickCursor->setColor(sf::Color(100,255,255,111));
    brickCursor->setPosition(pos_x, pos_y);
    addEntity(brickCursor);
}

void EditMapScene::handleEvents() {
    sf::Event event;
    while( game->window.pollEvent(event ) ) {
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
            else if( event.key.code == sf::Keyboard::Space ) {
                placeBrick();
            }
            else if( event.key.code == sf::Keyboard::BackSpace ) {
                undo();
            }
            else if( event.key.code == sf::Keyboard::Return ) {
                playMap();
            }
            else if(event.key.code == sf::Keyboard::Num1) {
                saveMapToFile("map1.ark");
            }
            else if(event.key.code == sf::Keyboard::Num2 ) {
                saveMapToFile("map2.ark");
            }
            else if(event.key.code == sf::Keyboard::Num3 ) {
                saveMapToFile("map3.ark");
            }
            else if(event.key.code == sf::Keyboard::S ) {
                saveMapToFile("mapUser.ark");
            }
            else if(event.key.code == sf::Keyboard::L ) {
                loadMapFromFile("mapUser.ark");

            }

            else if(event.key.code == sf::Keyboard::C ) {
                if(chosenCursor == 2) { chosenCursor = 0; }
                else { chosenCursor++; }
                float pos_x = brickCursor->getPosition().x;
                float pos_y = brickCursor->getPosition().y;
                removeEntity(brickCursor);
                mapEntities.remove(brickCursor);
                makeCursor(pos_x, pos_y);
            }
        }
    }
}

void EditMapScene::placeBrick() {
    bool draw = 1;
    for(auto i: mapEntities) {
        if( brickCursor->getPosition().x + brickCursor->getWidth() <= i->getPosition().x ||
            brickCursor->getPosition().x >= i->getPosition().x + i->getWidth() ||
            brickCursor->getPosition().y + brickCursor->getHeight() <= i->getPosition().y ||
            brickCursor->getPosition().y >= i->getPosition().y + i->getHeight()) {
        }
        else {
            draw = 0;
            break;
        }
    }
    if(draw) {
        GraphicalEntity* brick = makeBrick();
        removeEntity(brickCursor);
        mapEntities.remove(brickCursor);
        makeCursor(brick->getPosition().x, brick->getPosition().y);
    }
}

GraphicalEntity* EditMapScene::makeBrick() {
    GraphicalEntity* brick;
    switch(chosenCursor) {
        case TYPE::BRICK:
            brick = new Brick(this, resourceManager.getTextureFromMap("Brick"));
            break;
        case TYPE::SOLIDBRICK:
            brick = new SolidBrick(this, resourceManager.getTextureFromMap("SolidBrick"));
            break;
        case TYPE::BARRIER:
            brick = new Barrier(this, resourceManager.getTextureFromMap("Barrier"));
            break;
        default:
            brick = new Brick(this, resourceManager.getTextureFromMap("Brick"));
            break;
    }
    sf::Color color = brick->getColor();
    brick->setColor(sf::Color(color.r,color.g, color.b,255));
    brick->setPosition(brickCursor->getPosition().x,brickCursor->getPosition().y);
    addEntity(brick);
    mapEntities.push_back(brick);
    return brick;
}

void EditMapScene::undo() {
    if(!mapEntities.empty()) {
        removeEntity(brickCursor);
        float pos_x = mapEntities.back()->getPosition().x;
        float pos_y = mapEntities.back()->getPosition().y;
        removeEntity(mapEntities.back());
        mapEntities.pop_back();
        makeCursor(pos_x, pos_y);
    }
}

void EditMapScene::playMap() {
    GameplayScene* gameplayScene = new GameplayScene(game, mapEntities);
    for(auto i : mapEntities){
        removeEntity(i);
        i->scene = gameplayScene;
    }
    exitScene(gameplayScene);
}

void EditMapScene::exitScene(Scene *nextScene) {
    if(nextScene != NULL){
        Scene::exitScene(nextScene);
    }
    else{
        Scene::exitScene(new MenuScene(game));
    }
}

void EditMapScene::saveMapToFile(std::string filePath) {
    std::ofstream file(filePath.c_str());
    if( !file.good() ) return;
    for (auto i : mapEntities){
        file<<i->type<<" "
        <<i->getPosition().x<<" "
        <<i->getPosition().y<<"\n";
    }
    file.close();
}

void EditMapScene::moveEntity(GraphicalEntity *brickCursor, int direction) {
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
        float minHeight = height*14;
        if(pos_y >= minHeight) pos_y = minHeight - height;
        brickCursor->setPosition(pos_x, pos_y);
    }
}

void EditMapScene::loadMapFromFile(std::string filePath) {

    for(auto i : mapEntities){ // clear map
        removeEntity(i);
    }
    mapEntities.clear();

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
            mapEntities.push_back(brick);
            addEntity(brick);
        }
        if(type=="SolidBrick"){
            SolidBrick *solidBrick = new SolidBrick(this,resourceManager.getTextureFromMap("SolidBrick"));
            solidBrick->setPosition(pos_x,pos_y);
            mapEntities.push_back(solidBrick);
            addEntity(solidBrick);
        }
        if(type=="Barrier"){
            Barrier *barrier = new Barrier(this,resourceManager.getTextureFromMap("Barrier"));
            barrier->setPosition(pos_x,pos_y);
            mapEntities.push_back(barrier);
            addEntity(barrier);
        }
    }
    file.close();
}
