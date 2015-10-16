#pragma once

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <memory>

class ResourceManager {
private:
    std::map<std::string,sf::Texture&>TextureMap;

public:
    void loadTextureFromFile(std::string name, std::string filepath);
    void addTextureToMap(std::string name, sf::Texture *texture);
    sf::Texture & getTextureFromMap(std::string name);
};


