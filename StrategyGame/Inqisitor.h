#pragma once

#include "Actors.h"
#include <SFML\Graphics.hpp>

class Actors;

class Inqisitor : public Actors {
public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual void save(std::ofstream& fout) override;
};
