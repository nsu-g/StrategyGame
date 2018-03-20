#include "WorldModel.h"
#include <fstream>
// Initialize model with zero
WorldModel* WorldModel::WORLD = nullptr;

WorldModel::WorldModel()
{
	auto ps = std::make_shared<Student>();
	actors.push_back(ps);
	orders.push_back(std::make_shared<MoveOrder>(ps, sf::Vector2u(5,1)));
}


void WorldModel::SaveLevel(std::string filename)
{
 	auto& actors = WorldModel::getWorldInstance()->actors;
 	auto& landscape = WorldModel::getWorldInstance()->landscape;
 	std::ofstream fout("H:/" + filename + ".txt");
 	for (int i = 0; actors.size(); i++)
 	{
		//actors[i]->save_me(fout);
 	}
	for (int i = 0; landscape.size(); i++)
	{
		//landscape[i]->save_me(fout);
	}
	fout.close();
}

WorldModel* WorldModel::getWorldInstance()
{
	if (WORLD != nullptr)
		return WORLD;
	return WORLD = new WorldModel();
}

