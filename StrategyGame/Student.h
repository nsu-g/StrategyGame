#pragma once
#include "GameObject.h"
#include "WorldController.h"

class Student : public GameObject {
	sf::Vector2u pos;
public:
	virtual void render(sf::RenderTarget& r) override
	{
		sf::CircleShape shape;
		shape.setRadius(17);
		shape.setFillColor(sf::Color::Red);
		WorldController wc(30, 30, 20);
		shape.setPosition(wc.mapToScreen(pos) - sf::Vector2f(17, 17));
		r.draw(shape);
	}
	virtual void update() override
	{

	}
	virtual sf::Vector2u& position() override
	{
		return pos;
	}
};