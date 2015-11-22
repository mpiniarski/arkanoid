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

//void ResourceManager::loadSoundBufferFromFile(string name, string filepath) {
//    sf::SoundBuffer *sb = new sf::SoundBuffer();
//    sb->loadFromFile(filepath);
//    addSoundBufferToMap(name,sb);
//}
//
//void ResourceManager::addSoundBufferToMap(std::string name, sf::SoundBuffer *sb) {
//    SoundBufferMap.insert( {name,*sb} );
//}
//
//sf::SoundBuffer &ResourceManager::getSoundBufferFromMap(std::string name) {
//    auto found = SoundBufferMap.find(name);
//    return (found->second);
//}

ResourceManager::~ResourceManager() {
    for (auto i :TextureMap){
        delete(&i.second);
    }
    for (auto i :FontMap){
        delete(&i.second);
    }
}
