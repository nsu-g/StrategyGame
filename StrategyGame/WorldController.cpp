#include "WorldController.h"

WorldController::WorldController(unsigned int offset_x, unsigned int offset_y, float hex_radius) :
	offset_x(offset_x),
	offset_y(offset_y),
	hex_radius(hex_radius)
{
	hex_width = hex_radius * 2 * cos(30 * pi / 180.0f);
	hex_h = hex_radius * sin(30 * pi / 180.0f);
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

std::vector<std::shared_ptr<GameObject>> WorldController::getNearActors(GameObject& go)
{
	return{};
}

std::vector<std::shared_ptr<GameObject>> WorldController::getNearLandscape(GameObject& go)
{
	return{};
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