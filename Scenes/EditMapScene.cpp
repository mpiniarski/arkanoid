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
    resourceManager.loadTextureFromFile("Platform","res/img/platform.png");
    resourceManager.loadTextureFromFile("Brick","res/img/brick.png");
    resourceManager.loadTextureFromFile("SolidBrick","res/img/solidBrick.png");
    resourceManager.loadTextureFromFile("Barrier","res/img/barrier.png");
    resourceManager.loadFontFromFile("Font1","res/font/new-academy/new-academy.ttf");
}

void EditMapScene::createEntities() {
    Platform* platform =new Platform(this,resourceManager.getTextureFromMap("Platform"));
    addEntity(platform);

    makeCursor(0,0);

    TextEntity* placeElement = new TextEntity(this, "Place element: Space", resourceManager.getFontFromMap("Font1"));
    placeElement->setCharacterSize(20);
    placeElement->setPosition(10, (game->getWindowHeight() - 6*placeElement->getHeight()-16));
    addEntity(placeElement);
    TextEntityMap.insert({ "placeElement", placeElement });

    TextEntity* undo = new TextEntity(this, "Undo: Backspace", resourceManager.getFontFromMap("Font1"));
    undo->setCharacterSize(20);
    undo->setPosition(10, (game->getWindowHeight() - 4.5*undo->getHeight()-16));
    addEntity(undo);
    TextEntityMap.insert({ "undo", undo });

    TextEntity* changeOption = new TextEntity(this, "Change type: C", resourceManager.getFontFromMap("Font1"));
    changeOption->setCharacterSize(20);
    changeOption->setPosition(10, (game->getWindowHeight() - 3*changeOption->getHeight()-16));
    addEntity(changeOption);
    TextEntityMap.insert({ "changeOption", changeOption });

    TextEntity* playMap = new TextEntity(this, "Play map: Enter", resourceManager.getFontFromMap("Font1"));
    playMap->setCharacterSize(20);
    playMap->setPosition(10, (game->getWindowHeight() - 1.5*playMap->getHeight()-16));
    addEntity(playMap);
    TextEntityMap.insert({ "playMap", playMap });
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
            else if( event.key.code == sf::Keyboard::Space ) {
                placeBrick();
            }
            else if( event.key.code == sf::Keyboard::BackSpace ) {
                undo();
            }
            else if( event.key.code == sf::Keyboard::Return ) {
                playMap();
            }
            else if(event.key.code == sf::Keyboard::S ) {
                saveMapToFile("map1.ark");
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
        float minHeight = height*16;
        if(pos_y >= minHeight) pos_y = minHeight - height;
        brickCursor->setPosition(pos_x, pos_y);
    }
}




