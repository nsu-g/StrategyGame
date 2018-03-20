#pragma once

#include "GameObject.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>

class City : public GameObject {
	
	std::vector<int> dw;
	float relig; 
	std::vector<float> murd; 
	bool pick;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	
	std::vector<int> dwellers();
	
	float faith();

	std::vector<float> kill();

	void pick_up();

};