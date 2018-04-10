#pragma once
#include <memory>
#include <SFML\Main.hpp>
#include "GameObject.h"
#include "Order.h"
class AttackOrder : public Order {
	std::shared_ptr<Actors> subj;
	std::shared_ptr<Actors> obj;
public:
	AttackOrder(std::shared_ptr<Actors> subj, std::shared_ptr<Actors> obj) :
		subj(subj),
		obj(obj)
	{

	}

	virtual std::shared_ptr<Actors> subject()
	{
		return subj;
	}

	virtual bool finished()
	{
		
	}
};