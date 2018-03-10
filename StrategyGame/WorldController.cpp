#include "WorldController.h"
#include "GameObject.h"
#include "WorldRenderer.h"

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

	float x0;
	float y0;
	float xf;
	float yf;
	float a;
	float Len;
	float MinDistance;
	float x_steper;
	float y_steper;
	float OneStep_x;
	float OneStep_y;
	float IStep;
	float JStep;

	x0 = 30 - (StartPosition.x % 2) * offset_x + StartPosition.y * 2 * hex_radius * cos(30 * pi / 180.f) + hex_radius * sqrt(3) / 2;
	y0 = 30 + StartPosition.x * offset_y + hex_radius;

	xf = 30 - (EndPosition.x % 2) * offset_x + EndPosition.y * 2 * hex_radius * cos(30 * pi / 180.f) + hex_radius * sqrt(3) / 2;
	yf = 30 + EndPosition.x * offset_y + hex_radius;

	OneStep_x = 30 - (sf::Vector2u{ 1,1 }.x % 2) * offset_x + sf::Vector2u{1,1}.y * 2 * hex_radius * cos(30 * pi / 180.f) + hex_radius * sqrt(3) / 2;
	OneStep_y = 30 + sf::Vector2u{1,1}.x * offset_y + hex_radius;

	x_steper = x0;
	y_steper = y0;

	while (x_steper != xf && y_steper != yf)
	{
		MinDistance = sqrt(pow((x_steper - xf), 2) + pow((y_steper - yf), 2));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{

				IStep = 30 - (i % 2) * offset_x + j * 2 * hex_radius * cos(30 * pi / 180.f) + hex_radius * sqrt(3) / 2;
				JStep = 30 + i * offset_y + hex_radius;

				sf::Vector2f IterHex = { x_steper - OneStep_x + IStep,y_steper - OneStep_y + JStep };

				a = (yf - y0) / (xf - x0);
				Len = (pow(IterHex.x - (x_steper + IterHex.x + a*(y_steper - IterHex.y) + sqrt(pow(x_steper + xf + a*(y_steper - IterHex.y), 2) - 4 * (1 + a)*(x_steper*IterHex.x))) / (2 * (1 + a)), 2) +
					+pow(IterHex.y - y_steper + a*((x_steper + IterHex.x + a*(y_steper - IterHex.y) + sqrt(pow(x_steper + IterHex.x + a*(y_steper - IterHex.y), 2) - 4 * (1 + a)*(x_steper*IterHex.x))) / (2 * (1 + a))), 2));

				if (MinDistance > Len)
				{
					MinDistance = Len;
					direction.x = i;
					direction.y = j;
				}

			}
		}

		StepsVector.push_back(direction);

		x_steper = x_steper + 30 - (direction.x % 2) * offset_x + direction.y * 2 * hex_radius * cos(30 * pi / 180.f) + hex_radius * sqrt(3) / 2;
		y_steper = y_steper + 30 + direction.x * offset_y + hex_radius;
	}
	return(StepsVector);
}

bool WorldController::move(GameObject& go, sf::Vector2i direction)
{
	if (go.position().x == 0 && direction.x < 0)
	{
		return false;
	}
	if (go.position().y == 0 && direction.y < 0)
	{
		return false;
	}

	go.position().x = go.position().x + direction.x;
	go.position().y = go.position().y + direction.y;
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