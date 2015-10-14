#include "Engine/Game.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	Game game("Arkanoid by Asia and Marcin");

	while( game.Window.isOpen() )
	{
		sf::Event event;
		while( game.Window.pollEvent( event ) )
		{
			if( event.type == sf::Event::Closed )
				game.Window.close();
			if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
				game.Window.close();

		}
		game.Window.clear( sf::Color( 111, 0, 0 ) );
		game.Window.display();
	}
	return 0;
}
