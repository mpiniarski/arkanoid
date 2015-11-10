#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Scene;

class Game {
private:
    float FPS;
public:
    sf::RenderWindow Window;
    Scene* currentScene;

public:
    Game(std::string title, int width, int height);
    ~Game();
    void endGame();
    void launchScene(Scene* scene);
    int getWindowWidth() { return Window.getSize().x;}
    int getWindowHeight() { return Window.getSize().y;}
    float getFPS() { return FPS;}
};

