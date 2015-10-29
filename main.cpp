#include "Engine/Game.h"
#include "GameplayScene.h"
#include "MenuScene.h"

using namespace std;


int main()
{
	Game game("Arkanoid by Asia and Marcin",800,600);

	MenuScene *scene = new MenuScene(&game);
	game.launchScene(scene);

	return 111;
}
