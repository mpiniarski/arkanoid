#include "ResourceManager.h"

using namespace std;

void ResourceManager::loadTextureFromFile(string name, string filepath){
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(filepath);
    addTextureToMap(name,texture);
}

void ResourceManager::addTextureToMap(string name, sf::Texture *texture) {
    TextureMap.insert( {name,*texture} );
}

sf::Texture &ResourceManager::getTextureFromMap(std::string name) {
    auto found = TextureMap.find(name);
    return (found->second);
}

void ResourceManager::loadFontFromFile(string name, string filepath) {
    sf::Font *font = new sf::Font();
    font->loadFromFile(filepath);
    addFontToMap(name,font);
}

void ResourceManager::addFontToMap(std::string name, sf::Font *font) {
    FontMap.insert( {name,*font} );
}

sf::Font &ResourceManager::getFontFromMap(std::string name) {
    auto found = FontMap.find(name);
    return (found->second);
}
