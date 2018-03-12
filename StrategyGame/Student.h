#pragma once

#include "Actors.h"
#include <SFML\Graphics.hpp>
#include "MoveOrder.h"

class Actors;

class Student: public Actors {


public:
	virtual void render(sf::RenderTarget& r);

	virtual void update(); 


};