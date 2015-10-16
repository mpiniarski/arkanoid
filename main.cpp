#include "Engine/Game.h"
#include "Engine/Scene.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	Game game("Arkanoid by Asia and Marcin");

	Scene *scene = new Scene("Menu",&game);
	scene->run();


	delete scene;
	return 111;
}
