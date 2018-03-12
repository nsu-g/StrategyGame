#include <SFML/Graphics.hpp>
#include "WorldController.h"

#include "WorldRenderer.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	window.setVerticalSyncEnabled(true);
	//sf::View gameView;

	//gameView.s
	
	WorldRenderer wr(window);
	WorldController wc(30,30,20);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
		wc.update();
		wr.render();
		
		sf::sleep(sf::milliseconds(20));
		
		window.display();
	}

	return 0;
}