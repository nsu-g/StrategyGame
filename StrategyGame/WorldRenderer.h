#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "WorldModel.h"
class WorldRenderer
{
	const float pi = 3.14159265358979323846;
	float radius = 20;
	sf::RenderTarget& renderer;


	void renderHex(float ox, float oy) 
	{
		sf::ConvexShape polygon;
		polygon.setPointCount(6);

		for (int i = 0; i < 6; i++)
		{
			float angle_deg = i*60 + 30;
			float x = radius*cos(angle_deg * pi / 180.f);
			float y = radius*sin(angle_deg * pi / 180.f);

			polygon.setPoint(i, sf::Vector2f(x, y));
		}
		
		polygon.setOutlineColor(sf::Color::Red);
		polygon.setOutlineThickness(2);
		polygon.setPosition(ox, oy);
		polygon.setFillColor(sf::Color::Black);
		renderer.draw(polygon);
	}

	void renderGrid()
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
				radius = 5;
			else
				radius = 20;
			float x = radius*(cos(30 * pi / 180.f)-cos(150 * pi / 180.f));
			renderHex(30+i*x,30);
		}

		for (int i = 0; i < 10; i++)
		{
			float x = radius*(cos(30 * pi / 180.f) - cos(150 * pi / 180.f));

			float dx = radius*(cos((30+0*60) * pi / 180.f) + cos((30+1*60) * pi / 180.f));

			float dy = radius*(sin((30 + 0 * 60) * pi / 180.f) + sin((30 + 1 * 60) * pi / 180.f));
			renderHex(30 + dx+i*x, 30+dy);
		}
	}

public:
	WorldRenderer(sf::RenderTarget& renderer) : renderer(renderer)
	{

	}

	void render()
	{
		renderGrid();
		for (auto& i : WorldModel::getWorldInstance()->actors)
		{
			i->render(renderer);
		}
	}
};