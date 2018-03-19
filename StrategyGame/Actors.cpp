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

	texture1.loadFromFile("Textures/Sm_bolter_hero_2.png");
	space.setTexture(texture1);
	space.setScale(sf::Vector2f(0.1, 0.1));

	WorldController* wc = WorldController::Get_The_Controller_Instance();

	space.setPosition(wc->mapToScreen(pos));

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

void Actors::check_max()
{
	if (this->hp > 100) this->hp = 100;
	if (this->relig > 100) this->relig = 100;
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
	return this->position();
}

int& Actors::get_power()
{
	return this->power;
}

