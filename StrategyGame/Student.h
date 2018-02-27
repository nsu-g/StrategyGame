#pragma once
#include "GameObject.h"
#include "WorldController.h"

class Student : public GameObject {
	sf::Vector2u pos;
public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override; 

	virtual sf::Vector2u& position() override
	{
		return pos;
	}
};