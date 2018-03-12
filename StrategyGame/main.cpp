#include <SFML/Graphics.hpp>
#include "WorldController.h"
#include <iostream>
#include "WorldRenderer.h"
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Default, settings);
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
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
					break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					wr.selectHex(event.mouseButton.x, event.mouseButton.y);
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}
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