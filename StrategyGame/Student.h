#pragma once

#include "GameObject.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>
#include "MoveOrder.h"

class Student : public GameObject {
	sf::Vector2u pos;
	sf::Sprite space_marine;
	sf::Texture texture1;
public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override; 

	virtual sf::Vector2u& position() override

	{
		return pos;
	}

	virtual std::vector<sf::Vector2i>  Student::ABMovement(sf::Vector2u endPosition);

};