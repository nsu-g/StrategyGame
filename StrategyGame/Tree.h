#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class GameObject;

class Tree : public GameObject {
	sf::Vector2u pos;
	sf::Sprite Tree;
	sf::Texture texture;
public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;
	
};