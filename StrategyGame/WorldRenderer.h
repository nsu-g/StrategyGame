
#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "WorldModel.h"
class WorldRenderer
{
	const float pi = 3.14159265358979323846;
	float radius = 20;
	sf::RenderTarget& renderer;

	std::pair<float, float> chosenHex = std::pair<float, float>(-1, -1);

	std::pair<float, float> pixelToHex(float x, float y) 
	{
		auto result = std::pair<float, float>(-1, -1);
		float x_offset = 2 * radius * cos(30 * pi / 180.f) * cos(60 * pi / 180.f); //при переходе на новую строчку через раз надо будет смещать первый шестиугольник в ряду на такой шаг вправо или влево.
		float y_offset = 2 * radius * cos(30 * pi / 180.f) * sin(60 * pi / 180.f); //при переходе на новую строчку всякий раз надо будет смещать первый шестиугольник в ряду на такой шаг вниз.

		float distance = std::numeric_limits<float>::max();
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++) 
			{
				float x_hexCenter = 30 - (i % 2) * x_offset + j * 2 * radius * cos(30 * pi / 180.f) + radius * sqrt(3) / 2;
				float y_hexCenter = 30 + i * y_offset + radius;
				float dx = x - x_hexCenter;
				float dy = y - y_hexCenter;
				float newDistance = sqrt(dx * dx + dy * dy);
				
				if (newDistance > radius)
				{
					continue;
				}
				if (newDistance <= distance) 
				{
					distance = newDistance;
					result.first = i;
					result.second = j;
				}
			}
		}
		return result;
	}


	void renderHex(float ox, float oy)
	{
		sf::CircleShape hexagon(radius, 6);
		hexagon.setPosition(ox, oy);
		hexagon.setOutlineThickness(1);
		hexagon.setFillColor(sf::Color::Transparent);
		hexagon.setOutlineColor(sf::Color::Red);

		renderer.draw(hexagon);
	}

	void renderGreenHex(float ox, float oy)
	{
		sf::CircleShape hexagon(radius, 6);
		hexagon.setPosition(ox, oy);
		hexagon.setOutlineThickness(1);
		hexagon.setFillColor(sf::Color::Transparent);
		hexagon.setOutlineColor(sf::Color::Green);

		renderer.draw(hexagon);
	}

	void renderGrid()
	{
		float x_offset = 2 * radius * cos(30 * pi / 180.f) * cos(60 * pi / 180.f); //при переходе на новую строчку через раз надо будет смещать первый шестиугольник в ряду на такой шаг вправо или влево.
		float y_offset = 2 * radius * cos(30 * pi / 180.f) * sin(60 * pi / 180.f); //при переходе на новую строчку всякий раз надо будет смещать первый шестиугольник в ряду на такой шаг вниз.

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				renderHex(30 - (i % 2) * x_offset + j * 2 * radius * cos(30 * pi / 180.f), 30 + i * y_offset);
			}
		}
		renderGreenHex(30 - ((int)chosenHex.first % 2) * x_offset + chosenHex.second * 2 * radius * cos(30 * pi / 180.f), 30 + chosenHex.first * y_offset);

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
			//i->render(renderer);
		}
	}

	void selectHex(float ox, float oy)
	{
		float x_offset = 2 * radius * cos(30 * pi / 180.f) * cos(60 * pi / 180.f); //при переходе на новую строчку через раз надо будет смещать первый шестиугольник в ряду на такой шаг вправо или влево.
		float y_offset = 2 * radius * cos(30 * pi / 180.f) * sin(60 * pi / 180.f); //при переходе на новую строчку всякий раз надо будет смещать первый шестиугольник в ряду на такой шаг вниз.

		chosenHex = pixelToHex(ox, oy);
	}

};