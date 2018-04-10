#include "Soldier.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"

class WorldController;

void Soldier::render(sf::RenderTarget& r)
{
	
}

void Soldier::update()
{

}

int Soldier::get_power()
{

	return this->power;
}

void Soldier::add_power(int add)
{
	this->power = this->power + add;
}

void Soldier::check_power()
{
	if (this->power > 100) this->power = 100;
	if (this->power < 0) this->power = 0;
}