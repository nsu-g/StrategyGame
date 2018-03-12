#include "WorldModel.h"
// Initialize model with zero
WorldModel* WorldModel::WORLD = nullptr;

WorldModel::WorldModel()
{
	auto ps = std::make_shared<Student>();
	actors.push_back(ps);
	orders.push_back(std::make_shared<MoveOrder>(ps, sf::Vector2u(5,1)));
}


WorldModel* WorldModel::getWorldInstance()
{
	if (WORLD != nullptr)
		return WORLD;
	return WORLD = new WorldModel();
}

