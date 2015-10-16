#include "ResourceManager.h"

using namespace std;

void ResourceManager::loadTextureFromFile(string name, string filepath){
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(filepath);
    TextureMap.insert( {name,*texture});
    addTextureToMap(name,texture);
}

void ResourceManager::addTextureToMap(string name, sf::Texture *texture) {
    TextureMap.insert( {name,*texture} );
}

sf::Texture &ResourceManager::getTextureFromMap(std::string name) {
    auto found = TextureMap.find(name);
    return (found->second);
}
