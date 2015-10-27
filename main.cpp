#include "Engine/Game.h"
#include "GameplayScene.h"
#include "MenuScene.h"

using namespace std;


int main()
{
	Game game("Arkanoid by Asia and Marcin",800,600);

	GameplayScene *scene = new GameplayScene(&game);
//	MenuScene *scene = new MenuScene(&game);
	scene->run();


	return 111;
}
