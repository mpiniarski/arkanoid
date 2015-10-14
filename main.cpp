#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	sf::RenderWindow appWindow( sf::VideoMode( 800, 600 ), "Arkanoid by Asia and Marcin"/*, sf::Style::Fullscreen*/ );
	appWindow.setFramerateLimit(75);

	while( appWindow.isOpen() )
	{
		sf::Event event;
		while( appWindow.pollEvent( event ) )
		{
			if( event.type == sf::Event::Closed )
				appWindow.close();
			if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
				appWindow.close();

		}
		appWindow.clear( sf::Color( 111, 0, 0 ) );
		appWindow.display();
	}
	return 0;
}
