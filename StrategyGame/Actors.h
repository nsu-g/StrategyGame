#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class GameObject;

class Actors : public GameObject {

protected:
	int hp;
	int relig;
	int power;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual void add_hp(int add);

	virtual void add_faith(int add);

	virtual int& health();
	
	virtual int& faith();
	
};