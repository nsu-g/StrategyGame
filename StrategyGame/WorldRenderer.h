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
		sf::CircleShape Hexagon_Internal(radius - 4, 6);
		sf::CircleShape Hexagon_External(radius, 6);

		Hexagon_Internal.setOutlineThickness(-1);
		Hexagon_Internal.setFillColor(sf::Color::Transparent);
		Hexagon_Internal.setOutlineColor(sf::Color(255, 0, 0, 150));
		Hexagon_Internal.setOrigin(radius - 4, radius - 4);
		Hexagon_Internal.setPosition(sf::Vector2f(ox, oy));

		Hexagon_External.setOutlineThickness(-1);
		Hexagon_External.setFillColor(sf::Color::Transparent);
		Hexagon_External.setOrigin(radius, radius);
		Hexagon_External.setPosition(sf::Vector2f(ox, oy));
		Hexagon_External.setOutlineColor(sf::Color::Red);

		renderer.draw(Hexagon_External);
		renderer.draw(Hexagon_Internal);
	}

	void renderGrid()
	{
		float x_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*cos(60 * pi / 180.f); //при переходе на новую строчку через раз надо будет смещать первый шестиугольник в ряду на такой шаг вправо или влево.
		float y_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*sin(60 * pi / 180.f); //при переходе на новую строчку всякий раз надо будет смещать первый шестиугольник в ряду на такой шаг вниз.

		for (int i = 0; i < 10; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				renderHex(30 - (i % 2)*x_offset + j* (2 * radius*cos(30 * pi / 180.f) - 1), 30 + i*y_offset);
			}
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