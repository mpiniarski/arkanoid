#include "Scene.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

Scene::Scene(string name, Game *game) {
    this->name = name;
    this->game = game;

    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile("hostile_shot.png");
    TextureMap.insert( {"texture1",texture} );

    std::unordered_map<std::string,sf::Texture*>::const_iterator got = TextureMap.find ("texture1");
    sf::Sprite *sprite = new sf::Sprite( *got->second );
    sprite->setPosition(50,50);
    SpriteList.push_back(sprite);

}

void Scene::run(){
    while( game->Window.isOpen() )
    {
        handleEvents();
        renderWindow();
    }
}

void Scene::handleEvents() {
    sf::Event event;
    while( game->Window.pollEvent( event ) )
    {
        if( event.type == sf::Event::Closed )
            game->Window.close();
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
            game->Window.close();

    }
}

void Scene::renderWindow() {
    game->Window.clear( sf::Color( 0, 0, 0 ) );

    for( auto i = SpriteList.begin(); i!=SpriteList.end(); i++){
        game->Window.draw(**i);
    }

    game->Window.display();
}
