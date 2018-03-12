#pragma once

#include "Landscape.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>

class Food : public Landscape {
	sf::Vector2u pos;
	sf::Sprite food;
	sf::Texture texture;
	int hp;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	int hp();
};