#include "Actors.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"
#include "City.h"

class WorldController;
class Actors;
class City;
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

int& Actors::health()
{
	return this->hp;
}

int& Actors::faith()
{
	return this->relig;
}

sf::Vector2u& Actors::loc_position()
{
	auto& world = WorldModel::getWorldInstance()->landscape;
	for (int i = 0; i < world.size(); i++)
	{
		if (world[i]->position() == this->position())
		{
			City* pf = dynamic_cast<City*>(&(*(world[i])));
			if (pf != nullptr)
			{
				if (this->position() == pf->position()) return this->loc_pos;
			}
		}
	}


}