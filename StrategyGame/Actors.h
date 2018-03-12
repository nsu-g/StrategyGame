#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class GameObject;

class Actors : public GameObject {

protected:
	int hp;
	int faith;
	int power;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual void add_hp(int add)
	{
		this->hp = this->hp + add;
	}

	virtual void add_faith(int add)
	{
		this->faith = this->faith + add;
	}

	virtual int& hp()
	{
		return this->hp;
	}
	
	virtual int& faith()
	{
		return this->faith;
	}
};