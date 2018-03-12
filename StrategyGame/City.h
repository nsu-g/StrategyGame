#pragma once

#include "Landscape.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>

class City : public Landscape {
	std::vector<int> dwellers;
	float faith; // вера в процентах
	std::vector<float> kill; // (для инквизитора, для еретиков) или наоборот
	bool pick;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual sf::Vector2u& position() override

	{
		return pos;
	}
	
	std::vector<int> dwellers();
	
	float faith();

	std::vector<float> kill();

	void pick_up();

};