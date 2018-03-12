
#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "WorldModel.h"
class WorldRenderer
{
	const float pi = 3.14159265358979323846;

	float radius = 20;
	sf::RenderTarget& renderer;

	sf::Vector2i Chosen_Hex;

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

	void renderGreenHex(float ox, float oy)
	{
		sf::CircleShape hexagon(radius, 6);
		hexagon.setOrigin(radius, radius);
		hexagon.setPosition(ox, oy);
		hexagon.setOutlineThickness(1);
		hexagon.setFillColor(sf::Color::Transparent);
		hexagon.setOutlineColor(sf::Color::Green);

		renderer.draw(hexagon);
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
	void draw_The_ChosenHex()
	{
		float x_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*cos(60 * pi / 180.f); //при переходе на новую строчку через раз надо будет смещать первый шестиугольник в ряду на такой шаг вправо или влево.
		float y_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*sin(60 * pi / 180.f); //при переходе на новую строчку всякий раз надо будет смещать первый шестиугольник в ряду на такой шаг вниз.

		renderGreenHex(30 - (Chosen_Hex.y % 2) * x_offset + Chosen_Hex.x * (2 * radius * cos(30 * pi / 180.f) - 1), 30 + Chosen_Hex.y * y_offset);
	}

public:
	WorldRenderer(sf::RenderTarget& renderer) : renderer(renderer)
	{
	}

	void render()
	{
		renderGrid();
		draw_The_ChosenHex();
		for (auto& i : WorldModel::getWorldInstance()->actors)
		{
			//i->render(renderer);
		}
	}

	void Find_The_Chosen_Hex(float x, float y)
	{
		float x_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*cos(60 * pi / 180.f); //при переходе на новую строчку через раз надо будет смещать первый шестиугольник в ряду на такой шаг вправо или влево.
		float y_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*sin(60 * pi / 180.f); //при переходе на новую строчку всякий раз надо будет смещать первый шестиугольник в ряду на такой шаг вниз.

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				float CurrentHex_Center_X = 30 - (i % 2) * x_offset + j * (2 * radius * cos(30 * pi / 180.f) - 1);
				float CurrentHex_Center_Y = 30 + i * y_offset;

				if ((abs(x - CurrentHex_Center_X) <= radius*cos(30 * pi / 180.f)) &&
					(abs(y - CurrentHex_Center_Y) <= radius - abs(x - CurrentHex_Center_X) / sqrt(3)))
				{
					Chosen_Hex = sf::Vector2i(j, i); //Именно в таком порядке, так как j - номер столбца в матрице, сиречь координата по X.
				}
			}
		}
		return;
	}

};