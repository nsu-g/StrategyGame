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
	return this->dw;
}

float City::faith()
{
	return this->relig;
}

std::vector<float> City::kill()
{
	return this->murd;
}

void City::pick_up()
{
	// Kolya knows, how check it
}