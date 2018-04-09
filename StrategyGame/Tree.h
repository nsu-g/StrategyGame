#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class GameObject;

class Tree : public GameObject {

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;
	
};