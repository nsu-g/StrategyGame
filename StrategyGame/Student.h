#pragma once
#include "GameObject.h"

class Student : public GameObject {
	unsigned int x, y;
	sf::CircleShape shape;
public:
	virtual void render(sf::RenderTarget& r)
	{
		shape.setRadius(20);
		shape.setFillColor(sf::Color::Red);
		shape.setPosition(x, y);
		r.draw(shape);
	}
	virtual void update() 
	{
		x++; y++;
	}
	virtual sf::Vector2u position()
	{
		return{ x,y };
	}
};