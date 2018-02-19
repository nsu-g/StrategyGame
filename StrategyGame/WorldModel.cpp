#include "WorldModel.h"
// Initialize model with zero
WorldModel* WorldModel::WORLD = nullptr;

WorldModel::WorldModel()
{
	actors.push_back(std::make_shared<Student>());
}


WorldModel* WorldModel::getWorldInstance()
{
	if (WORLD != nullptr)
		return WORLD;
	return WORLD = new WorldModel();
}