#pragma once

#include <SFML\System.hpp>
#include "Student.h"
#include "WorldModel.h"
//TODO : Singleton
class Student;
class Civilian;
class Actors;
class WorldController
{

	static WorldController* CONTROLLER;
	// Constructor is private so it can't be called from other code - Singletone pattern
	WorldController()
	{
		offset_x = 30;
		offset_y = 30;

		hex_radius = 20;
		hex_width = hex_radius * 2 * cos(30 * pi / 180.0f);
		hex_h = hex_radius * sin(30 * pi / 180.0f);

	}
	WorldController(const WorldController&) = delete;
	void operator=(const WorldController&) = delete;

	const float pi = 3.14159265358979323846;

	unsigned int offset_x;
	unsigned int offset_y;
	float hex_radius;
	float hex_width;
	float hex_h;

public:
	// TODO: move hex-related methods to renderer
	static WorldController* Get_The_Controller_Instance()
	{
		if (CONTROLLER != nullptr)
			return CONTROLLER;
		return CONTROLLER = new WorldController();
	}

	void Set_Offsets(int Offset_X, int Offset_Y);
	void Set_Radius(float Radius);

	sf::Vector2f mapToScreen(sf::Vector2u point);

	bool move(GameObject& go, sf::Vector2i direction);

	bool attack(GameObject& go, sf::Vector2i direction);

	bool attack(Student& go, sf::Vector2i direction);

	std::vector<std::shared_ptr<GameObject>> getNearActors(GameObject& go);

	std::vector<std::shared_ptr<GameObject>> getNearLandscape(GameObject& go);

	//TODO: handle all updates, delete orders that are finished, delete unnecessary objects
	void update();


};