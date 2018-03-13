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
	
	WorldRenderer* wr = WorldRenderer::Get_The_Renderer_Instance();
	WorldController* wc = WorldController::Get_The_Controller_Instance();
	wc->Set_Offsets(30, 30);
	wc->Set_Radius(20);

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
					wr->Find_The_Chosen_Hex(event.mouseButton.x, event.mouseButton.y);
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
		wc->update();
		wr->render(window);
		
		sf::sleep(sf::milliseconds(20));
		
		window.display();
	}

	return 0;
}