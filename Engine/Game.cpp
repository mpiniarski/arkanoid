#include "Game.h"
#include "Scene.h"

using namespace std;

Game::Game(string gameTitle):
        window(/*sf::VideoMode::getFullscreenModes()[1]*/sf::VideoMode(1280, 720), gameTitle/*, sf::Style::Fullscreen*/)
{
    currentScene = NULL;
    FPS = 60.0;
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(false);
}

void Game::launchScene(Scene *scene) {
    if(scene != NULL){
        if(currentScene != NULL){
            delete currentScene;
            currentScene = NULL;
        }
        currentScene = scene;
        currentScene->run();
    }
}

Game::~Game() {
    if (currentScene != NULL)
        delete currentScene;
        currentScene = NULL;
}
