#include "Engine/Game.h"
#include "GameplayScene.h"
#include "MenuScene.h"

using namespace std;


int main()
{
	Game *game = new Game("Arkanoid by Asia and Marcin");

	MenuScene *scene = new MenuScene(game);
	game->launchScene(scene);

	delete game;

	return 111;
}
