#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include "Order.h"

class Order;
class GameObject;

class Actors : public GameObject {

protected:
	int hp;
	int relig;
	int power;

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	virtual void Actors::update(std::shared_ptr<Order> &ord);

	virtual void add_hp(int add);

	virtual void add_faith(int add);

	virtual int& health();
	
	virtual int& faith();
	
	virtual void check_max();

	virtual int& get_power();

	std::map<std::shared_ptr<Actors>, bool> Actors::DefState(std::vector<std::shared_ptr<Actors>> Acts);
};