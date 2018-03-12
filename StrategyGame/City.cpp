#include "City.h"
class City;

void City::render(sf::RenderTarget& r)
{

}

void City::update()
{

}

std::vector<int> City::dwellers()
{
	if (pick) return this->dwellers;
}

float City::faith()
{
	if (pick) return this->faith;
}

std::vector<float> City::kill()
{
	if (pick) return this->kill;
}

void City::pick_up()
{
	// Kolya knows, how check it
}