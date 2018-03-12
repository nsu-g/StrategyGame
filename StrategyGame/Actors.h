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

	virtual void Actors::update(std::vector<std::shared_ptr<Order>>);

};