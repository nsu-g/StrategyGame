#include "WorldModel.h"

// Initialize model with zero
WorldModel* WorldModel::WORLD = nullptr;

WorldModel::WorldModel()
{
	/*auto ps = std::make_shared<Actors>();
	actors.push_back(ps);
	orders.push_back(std::make_shared<MoveOrder>(ps, sf::Vector2u(5,1)));*/
}


void WorldModel::SaveLevel(std::string filename)
{
	auto& actors = WorldModel::getWorldInstance()->actors;
	auto& landscape = WorldModel::getWorldInstance()->landscape;
	std::ofstream fout(filename + ".txt");
	for (int i = 0; actors.size(); i++)
	{
		actors[i]->save(fout);
	}
	for (int i = 0; landscape.size(); i++)
	{
		landscape[i]->save(fout);
	}
	fout.close();
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

void WorldModel::Deactivate_Actors()
{
	for (int i = 0; i < actors.size(); i++)
	{
		actors[i]->set_active(false);
	}
}

void WorldModel::Deactivate_Landscapes()
{
	for (int i = 0; i < landscape.size(); i++)
	{
		landscape[i]->set_active(false);
	}
}

