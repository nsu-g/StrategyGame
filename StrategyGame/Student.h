#pragma once

#include "GameObject.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>
#include "Actors.h"

class Actors;
class Student : public Actors {

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override; 

	//TODO: virtual void update(Order&) override;
	//TODO: virtual void update(MoveOrder&) override;

};