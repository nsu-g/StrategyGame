#pragma once

#include <SFML\Graphics.hpp>

//Abstract class which will be parent to other objects, has position, renders to image, updates when world changes
class GameObject
{
public:
	virtual void render(sf::RenderTarget&) = 0;
	virtual void update() = 0;
	virtual sf::Vector2u position() = 0;
};