#pragma once

#include "GameObject.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>

class Food : public GameObject {
	sf::Vector2u pos;
	sf::Sprite food;
	sf::Texture texture;
	int hp;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	int health();
};