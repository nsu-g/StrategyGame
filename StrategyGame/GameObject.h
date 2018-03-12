#pragma once

#include <SFML\Graphics.hpp>

//Abstract class which will be parent to other objects, has position, renders to image, updates when world changes
class GameObject
{
protected:
	sf::Vector2u pos;
	sf::Sprite sprite;
	sf::Texture texture;

public:
	virtual void render(sf::RenderTarget&) = 0;
	virtual void update() = 0;
	virtual sf::Vector2u& position()

	{
		return pos;
	}
};