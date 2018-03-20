#include "WorldController.h"
#include "Food.h"
class Food;
class WorldController;

WorldController* WorldController::CONTROLLER = nullptr;

void WorldController::Set_Offsets(int Offset_X,int Offset_Y)
{
	offset_x = Offset_X;
	offset_y = Offset_Y;
	return;
}

void WorldController::Set_Radius(float Radius)
{
	hex_radius = Radius;
	hex_width = hex_radius * 2 * cos(30 * pi / 180.0f);
	hex_h = hex_radius * sin(30 * pi / 180.0f);
	return;
}

sf::Vector2f WorldController::mapToScreen(sf::Vector2u point)
{
	if (point.y % 2 == 0)
	{
		return{ offset_x + hex_width*point.x, offset_y + (hex_radius + hex_h) * 2 * (point.y) / 2 };
	}
	else {
		return{ offset_x + hex_width / 2 + hex_width*point.x,
			offset_y + hex_radius + hex_h + (hex_radius + hex_h) * 2 * (point.y - 1) / 2 };
	}
}

bool WorldController::move(GameObject& go, sf::Vector2i direction)
{
	
	go.position().x = go.position().x + direction.x;
	go.position().y = go.position().y + direction.y;

	if (go.position().x == 0 && direction.x<0)
	{
		return false;
	}
	if (go.position().y == 0 && direction.y<0)
	{
		return false;
	}

	// TODO: check for direction length, other objects from WorldModel don't lie in that coord
	// return true if success
	
	return true;
}

bool WorldController::attack(GameObject& go, sf::Vector2i direction)
{
	return true;
	// TODO: check for direction length, other objects from WorldModel don't lie in that coord
	// return true if success
	//WorldController::getControllerInstance()->attack(*this, {1,1});
}

bool WorldController::attack(Student& go, sf::Vector2i direction)
{
	return true;
	// TODO: check for direction length, other objects from WorldModel don't lie in that coord
	// return true if success
}

std::vector<sf::Vector2u> WorldController::getNearCoord(sf::Vector2u go)
{
	std::vector<sf::Vector2u> neighbour;
	neighbour.push_back(go + sf::Vector2u(1, 0));
	neighbour.push_back(go + sf::Vector2u(0, 1));
	if (go.x != 0) neighbour.push_back(go + sf::Vector2u(-1, 0));
	if (go.y != 0) neighbour.push_back(go + sf::Vector2u(0, -1));
	if (go.y % 2 == 0)
	{
		if (go.y != 0 && go.x != 0) neighbour.push_back(go + sf::Vector2u(-1, -1));
		if (go.x != 0) neighbour.push_back(go + sf::Vector2u(-1, 1));
	}
	else
	{
		if (go.y != 0) neighbour.push_back(go + sf::Vector2u(1, -1));
		neighbour.push_back(go + sf::Vector2u(1, 1));
	}
	return neighbour;
}

std::vector<std::shared_ptr<Actors>> WorldController::getNearActors(GameObject& go)
{
	auto& world = WorldModel::getWorldInstance()->actors;
	auto neighbour = getNearCoord(go.position());
	std::vector<std::shared_ptr<Actors>> near(neighbour.size());
	for (int i = 0; i < neighbour.size(); i++)
	{
		for (unsigned int k = 0; k < world.size(); k++) 
		{
			if (world[k]->position() == neighbour[i])
			{
				near[i] = world[k];
			}
		}
	}
	return near;
}

std::vector<std::shared_ptr<GameObject>> WorldController::getNearLandscape(GameObject& go)
{
	auto& world = WorldModel::getWorldInstance()->landscape;
	auto neighbour = getNearCoord(go.position());
	std::vector<std::shared_ptr<GameObject>> near(neighbour.size());
	for (int i = 0; i < neighbour.size(); i++)
	{
		for (int k = 0; k < world.size(); k++) 
		{
			if (world[k]->position() == neighbour[i])
			{
				near[i] = world[k];
			}
		}
	}
	return near;
}

//TODO: handle all updates, delete orders that are finished, delete unnecessary objects
void WorldController::update()
{
	auto& ord = WorldModel::getWorldInstance()->orders;
	for (int i = 0; i < ord.size(); i++)
	{
		//TODO: track each actors' order (don't do it twice), use std::map<shared_ptr<Actor>, bool>
		ord[i]->subject()->update(); // update(ord[i])
		//TODO: if no orders given for an actor, do update() without orders
		if (ord[i]->finished())
		{
			ord.erase(ord.begin() + i);
			i--; // deleted element, elements shifted
		}
	}
}

void WorldController::eat(Actors& player)
{
	auto& lands = WorldModel::getWorldInstance()->landscape;
	for (int i = 0; i < lands.size(); i++)
	{
		if (lands[i]->position() == player.position())
		{
			Food* pf = dynamic_cast<Food*>(&(*(lands[i])));
			if (pf != nullptr)
			{
				player.add_hp(pf->health());
				lands.erase(lands.begin()+i);
				break;
			}
		}

	}
	player.check_max();
}