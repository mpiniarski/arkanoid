#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Scene;

class Game {
private:
    float FPS;
public:
    sf::RenderWindow window;
    Scene* currentScene;

public:
    Game(std::string gameTitle);
    ~Game();
    void launchScene(Scene* scene);

    int getWindowWidth() { return window.getSize().x;}
    int getWindowHeight() { return window.getSize().y;}
    float getFPS() { return FPS;}
};

