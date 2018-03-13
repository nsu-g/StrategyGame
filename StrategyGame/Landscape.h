#pragma once

#include "GameObject.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>
#include "MoveOrder.h"

class Landscape : public GameObject {


public:
	virtual void render(sf::RenderTarget& r) override = 0;

	virtual void update() override = 0;


};