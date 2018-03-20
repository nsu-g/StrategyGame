#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class GameObject;

class Actors : public GameObject {

protected:
	int hp;
	int relig;
	int power;
	sf::Vector2u loc_pos;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual void add_hp(int add);

	virtual void add_faith(int add);

	virtual int& health();
	
	virtual int& faith();
	
	virtual void check_max();

	virtual sf::Vector2u& loc_position();

	virtual int& get_power();

	virtual void save_me(std::ofstream fout) override = 0;
};