#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Scene;

class Game {
private:
    Scene* currentScene;
    float FPS;
public:
    sf::RenderWindow Window;

public:
    Game(std::string title, int width, int height);
    void launchScene(Scene* scene);
    int getWindowWidth() { return Window.getSize().x;}
    int getWindowHeight() { return Window.getSize().y;}
    float getFPS() { return FPS;}

};

