#include <SFML/Graphics.hpp>
#include "WorldController.h"
#include <iostream>
#include "WorldRenderer.h"
#include "Finite-State Machine.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	//sf::View gameView;

	//gameView.s
	
	Finite_State_Machine The_Machine(window);

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
					The_Machine.click(sf::Vector2i(sf::Mouse::getPosition(window))); //Стоит заметить, что позиция задаётся именно относительно окна.
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
		The_Machine.render();
		
		sf::sleep(sf::milliseconds(20));
		
		window.display();
	}

	return 0;
}