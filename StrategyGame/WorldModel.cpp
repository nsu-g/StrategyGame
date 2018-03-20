#include "WorldModel.h"
#include <fstream>
// Initialize model with zero
WorldModel* WorldModel::WORLD = nullptr;

WorldModel::WorldModel()
{
	auto ps = std::make_shared<Actors>();
	actors.push_back(ps);
	orders.push_back(std::make_shared<MoveOrder>(ps, sf::Vector2u(5,1)));
}


void WorldModel::SaveLevel(std::string filename)
{
// 	auto& actors = WorldModel::getWorldInstance()->actors;
// 	auto& landscape = WorldModel::getWorldInstance()->landscape;
// 	std::ofstream fout("H:\\" + filename + ".txt");
// 	fout << "Class" << '\t' << "global_pos" << '\t';
// 	fout << "local_pos" << '\n';
// 	for (int i = 0; actors.size(); i++)
// 	{
// 		fout << "Actor" << '\t' << actors[i]->position() << '\t';
// 		fout << actors[i]->loc_position() << '\t';
// 		fout << actors[i]->health() << '\t' << actors[i]->faith() << '\t';
// 		fout << actors[i]->get_power() << '\n';
// 	} 
}

WorldModel* WorldModel::getWorldInstance()
{
	if (WORLD != nullptr)
		return WORLD;
	return WORLD = new WorldModel();
}

