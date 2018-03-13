#pragma once
#include <memory>
#include <SFML\Main.hpp>
#include "GameObject.h"
#include "Order.h"
class MoveOrder : public Order {
	std::shared_ptr<Actors> subj;
	sf::Vector2u endPosition;
public:
	MoveOrder(std::shared_ptr<Actors> subj, sf::Vector2u endPosition) :
		subj(subj),
		endPosition(endPosition)
	{

	}

	virtual std::shared_ptr<Actors> subject()
	{
		return subj;
	}
	
	virtual bool finished()
	{
		return endPosition == (*subj).position();
	}
};