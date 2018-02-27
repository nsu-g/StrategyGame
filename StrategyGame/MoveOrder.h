#pragma once
#include <memory>
#include <SFML\Main.hpp>
#include "GameObject.h"
#include "Order.h"
class MoveOrder : public Order {
	std::shared_ptr<GameObject> subj;
	sf::Vector2u endPosition;
public:
	MoveOrder(std::shared_ptr<GameObject> subj, sf::Vector2u endPosition) :
		subj(subj),
		endPosition(endPosition)
	{

	}

	virtual std::shared_ptr<GameObject> subject()
	{
		return subj;
	}
	
	virtual bool finished()
	{
		return endPosition == (*subj).position();
	}
};