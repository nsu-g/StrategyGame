#include "Actors.h"
#include "City.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"
#include "Order.h"

class City;
class WorldController;
class Actors;
void Actors::render(sf::RenderTarget& r)
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

void Actors::check_max()
{
	if (this->hp > 100) this->hp = 100;
	if (this->relig > 100) this->relig = 100;
}

int& Actors::get_power()
{
	return this->power;
}

std::map<std::shared_ptr<Actors>, bool> Actors::DefState(std::vector<std::shared_ptr<Actors>> Acts)
{
	
}

void Actors::update()
{
	auto& Acts = WorldModel::getWorldInstance()->actors;
	auto& Def = DefState(Acts);
}

void Actors::update(std::shared_ptr<Order> &ord)
{

}