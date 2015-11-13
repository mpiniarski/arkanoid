#include "Game.h"
#include "Scene.h"

using namespace std;

Game::Game(string title, int width, int height):
        Window(sf::VideoMode( width, height ), title/*, sf::Style::Fullscreen*/ )
{
    currentScene = NULL;
    FPS = 60.0;
    Window.setFramerateLimit(75);
    Window.setVerticalSyncEnabled(true);
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

void Game::endGame() {
}
