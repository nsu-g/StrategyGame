#include "WorldModel.h"

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

void WorldModel::Render_Actors(sf::RenderTarget& The_Target) //Render all elements of the "actors" vector
{
	for (int i = 0; i < actors.size(); i++)
	{
		actors[i]->render(The_Target);
	}
}

void WorldModel::Render_Landscapes(sf::RenderTarget & The_Target) //Render all elements of the "landscape" vector
{
	for (int i = 0; i < landscape.size(); i++)
	{
		landscape[i]->render(The_Target);
	}
}

