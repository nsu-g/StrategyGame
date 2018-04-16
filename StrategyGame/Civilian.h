#pragma once

#include <string>

#include <SFML\Graphics.hpp>
#include "Actors.h"

class Actors;

class Civilian : public Actors {
public:

	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual void save(std::ofstream& fout) override;
};