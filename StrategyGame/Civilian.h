#pragma once

#include <SFML\Graphics.hpp>
#include "Actors.h"

class Actors;

class Civilian : public Actors {
public:

	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;


};