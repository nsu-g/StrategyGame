#include "Actors.h"
#include "City.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"

class City;
class WorldController;
class Actors;
void Actors::render(sf::RenderTarget& r)
{
}

void Actors::update()
{

}

void Actors::add_hp(int add)
{
	this->hp = this->hp + add;
}

void Actors::add_faith(int add)
{
	this->relig = this->relig + add;
}

int Actors::health()
{
	return this->hp;
}

int Actors::faith()
{
	return this->relig;
}

void Actors::check_max_min()
{
	if (this->hp < 0) this->hp = 0;
	if (this->hp > 100) this->hp = 100;
	if (this->relig < 0) this->relig = 0;
	if (this->relig > 100) this->relig = 100;
}

bool Actors::friendly()
{
	if (this->relig > 50) return false;
	return true;
}

