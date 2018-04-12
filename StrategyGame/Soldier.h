#pragma once

#include <SFML\Graphics.hpp>
#include "Actors.h"

class Actors;

class Soldier : public Actors {

	int power;

public:

	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual int get_power();
	
	virtual void add_power(int add);

	virtual void check_power();

	virtual void save(std::ofstream& fout) override;
};