#pragma once

#include "GameObject.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>

class Student : public GameObject {

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override; 

	//TODO: virtual void update(Order&) override;
	//TODO: virtual void update(MoveOrder&) override;

	virtual sf::Vector2u& position() override

	{
		return pos;
	}
};