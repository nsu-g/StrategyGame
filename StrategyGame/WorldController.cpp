#include "WorldController.h"
#include "GameObject.h"

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

std::vector<sf::Vector2i> WorldController::ABMovement(sf::Vector2u StartPosition,sf::Vector2u EndPosition)
{

	std::vector<sf::Vector2i> StepsVector;
	sf::Vector2i direction = { 0,0 };
	direction.x = EndPosition.x;
	direction.y = EndPosition.y;

	int x0;
	int y0;
	int xf;
	int yf;
	double a;
	double Len;
	double MinDistance;

	x0 = StartPosition.x;
	y0 = StartPosition.y;
	xf = EndPosition.x;
	yf = EndPosition.y;

	while (x0 != xf && y0 != yf)
	{
		MinDistance = sqrt(pow((x0 - xf), 2) + pow((y0 - yf), 2));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{

				sf::Vector2i IterHex = { x0 - 1 + i,y0 - 1 + j };

				a = (IterHex.y - y0) / (IterHex.x - x0);
				Len = (pow(IterHex.x - (x0 + IterHex.x + a*(y0 - IterHex.y) + sqrt(pow(x0 + xf + a*(y0 - IterHex.y), 2) - 4 * (1 + a)*(x0*IterHex.x))) / (2 * (1 + a)), 2) +
					+pow(IterHex.y - y0 + a*((x0 + IterHex.x + a*(y0 - IterHex.y) + sqrt(pow(x0 + IterHex.x + a*(y0 - IterHex.y), 2) - 4 * (1 + a)*(x0*IterHex.x))) / (2 * (1 + a))), 2));

				if (MinDistance > Len)
				{
					MinDistance = Len;
					direction.x = IterHex.x;
					direction.y = IterHex.y;
				}

			}
		}
		StepsVector.push_back(direction);
		x0 = x0 + direction.x;
		y0 = y0 + direction.y;
	}
	return(StepsVector);
}

bool WorldController::move(GameObject& go, sf::Vector2i direction)
{
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