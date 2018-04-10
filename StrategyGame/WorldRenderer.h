
#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "WorldModel.h"
#include "GameObject.h"
#include <vector>

class WorldRenderer
{
	static WorldRenderer* RENDERER;
	// Constructor is private so it can't be called from other code - Singletone pattern
	WorldRenderer()
	{
	}
	WorldRenderer(const WorldRenderer&) = delete;
	void operator=(const WorldRenderer&) = delete;
	
	const float pi = 3.14159265358979323846;
	float radius = 20;

	sf::Vector2u Chosen_Hex;

	bool A_Hex_Is_Active = 0;
	void renderHex(float ox, float oy, sf::RenderTarget& renderer)
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
	void renderGreenHex(float ox, float oy, sf::RenderTarget& renderer)
	{
		sf::CircleShape hexagon(radius, 6);
		hexagon.setOrigin(radius, radius);
		hexagon.setPosition(ox, oy);
		hexagon.setOutlineThickness(-1);
		hexagon.setFillColor(sf::Color::Transparent);
		hexagon.setOutlineColor(sf::Color::Green);

		renderer.draw(hexagon);
	}
	void renderGrid(sf::RenderTarget& renderer)
	{
		float x_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*cos(60 * pi / 180.f); //this is local offset of one particular line according to its position on the screen
		float y_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*sin(60 * pi / 180.f); //this is local offset of one particular line according to its position on the screen
		
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				renderHex(30 - (i % 2)*x_offset + j* (2 * radius*cos(30 * pi / 180.f) - 1), 30 + i*y_offset, renderer);
			}
		}
	}

	void DrawDeWay(sf::Vector2u first, std::vector<sf::Vector2i> steps, sf::RenderTarget& renderer)
	{
		sf::Vector2u start = first;
		sf::CircleShape hexagon(radius, 6);
		hexagon.setOrigin(radius, radius);
		hexagon.setPosition(start.x, start.y);
		hexagon.setOutlineThickness(1);
		hexagon.setFillColor(sf::Color::Green);
		hexagon.setOutlineColor(sf::Color::Transparent);
		renderer.draw(hexagon);
		
			for (int i; i < sizeof(steps); i++)
			{
				start.x = start.x + steps[i].x;
				start.y = start.y + steps[i].y;
			
				sf::CircleShape hexagon(radius, 6);
				hexagon.setOrigin(radius, radius);
				hexagon.setPosition(start.x, start.y);
				hexagon.setOutlineThickness(1);
				hexagon.setFillColor(sf::Color::Green);
				hexagon.setOutlineColor(sf::Color::Transparent);
				renderer.draw(hexagon);
			}
	}

public:
	static WorldRenderer* Get_The_Renderer_Instance();

	void render_Global_Screen(sf::RenderTarget& renderer);
	void Find_The_Chosen_Hex(float x, float y);
	void render_The_ChosenHex(sf::RenderTarget& renderer);
	bool Is_A_Hex_Active(); //This method would be usefull in the Machine.
	sf::Vector2u Get_The_Chosen_Hex(); //This method would be usefull in the Machine.
};