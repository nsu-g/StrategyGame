#include <SFML/Graphics.hpp>

#include "WorldRenderer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	//sf::View gameView;

	//gameView.s
	
	WorldRenderer wr(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		wr.render();
		sf::sleep(sf::milliseconds(20));
		
		window.display();
	}

	return 0;
}