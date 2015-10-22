#pragma once

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <memory>
#include <SFML/Graphics/Text.hpp>

class ResourceManager {
private:
    std::map<std::string,sf::Texture&>TextureMap;
    std::map<std::string,sf::Font&>FontMap;

public:
    void loadTextureFromFile(std::string name, std::string filepath);
    void addTextureToMap(std::string name, sf::Texture *texture);
    sf::Texture & getTextureFromMap(std::string name);

    void loadFontFromFile(std::string name, std::string filepath);
    void addFontToMap(std::string name, sf::Font *font);
    sf::Font & getFontFromMap(std::string name);
};


