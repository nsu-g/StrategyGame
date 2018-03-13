#pragma once

#include "Actors.h"
#include <SFML\Graphics.hpp>

class Actors;

class Inqisitor : public Actors {
	//int hp;
	//int faith;
public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	/*
	int hp() override
	{
		return hp;
	}
	
	int faith() override
	{
		return faith;
	}

	*/

};