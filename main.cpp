#include "Engine/Game.h"
#include "GameplayScene.h"
#include "MenuScene.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	Game game("Arkanoid by Asia and Marcin");

//	GameplayScene scene("Arkanoid",&game);
	MenuScene scene("Menu",&game);
	scene.run();


	return 111;
}
