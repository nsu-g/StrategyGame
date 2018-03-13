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
	if (pick) return this->dw;
}

float City::faith()
{
	if (pick) return this->relig;
}

std::vector<float> City::kill()
{
	if (pick) return this->murd;
}

void City::pick_up()
{
	// Kolya knows, how check it
}