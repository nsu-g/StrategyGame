#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class GameObject;

class Actors : public GameObject {

protected:
	int hp;
	int faith;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;


};